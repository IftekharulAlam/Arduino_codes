#include "boost/python.hpp"
#include "RF24/RF24.h"
#include "RF24Network/RF24Network.h"

namespace bp = boost::python;

// **************** expicit wrappers *****************
// where needed, especially where buffer is involved

void throw_ba_exception(void)
{
    PyErr_SetString(PyExc_TypeError, "buf parameter must be bytes or bytearray");
    bp::throw_error_already_set();
}

char* get_bytes_or_bytearray_str(bp::object buf)
{
    PyObject* py_ba;
    py_ba = buf.ptr();
    if (PyByteArray_Check(py_ba))
        return PyByteArray_AsString(py_ba);
    else if (PyBytes_Check(py_ba))
        return PyBytes_AsString(py_ba);
    else
        throw_ba_exception();

    return NULL;
}

int get_bytes_or_bytearray_ln(bp::object buf)
{
    PyObject* py_ba;
    py_ba = buf.ptr();
    if (PyByteArray_Check(py_ba))
        return PyByteArray_Size(py_ba);
    else if (PyBytes_Check(py_ba))
        return PyBytes_Size(py_ba);
    else
        throw_ba_exception();

    return 0;
}

bp::tuple read_wrap(RF24Network& ref, size_t maxlen)
{
    RF24NetworkHeader header;

    char* buf = new char[maxlen + 1];
    uint16_t len = ref.read(header, buf, maxlen);
    bp::object py_ba(bp::handle<>(PyByteArray_FromStringAndSize(buf, len)));
    delete[] buf;

    return bp::make_tuple(header, py_ba);
}

bp::tuple peek_read_wrap(RF24Network& ref, size_t maxlen)
{
    RF24NetworkHeader header;
    char* buf = new char[maxlen + 1];

    uint16_t len = rf24_min(maxlen, ref.peek(header));
    ref.peek(header, buf, len);
    bp::object py_ba(bp::handle<>(PyByteArray_FromStringAndSize(buf, len)));
    delete[] buf;

    return bp::make_tuple(header, py_ba);
}

bool write_wrap(RF24Network& ref, RF24NetworkHeader& header, bp::object buf)
{
    return ref.write(header, get_bytes_or_bytearray_str(buf), get_bytes_or_bytearray_ln(buf));
}

#if defined RF24NetworkMulticast
bool multicast_wrap(RF24Network& ref, RF24NetworkHeader& header, bp::object buf, uint8_t level)
{
    return ref.multicast(header, get_bytes_or_bytearray_str(buf), get_bytes_or_bytearray_ln(buf), level);
}
#endif // defined RF24NetworkMulticast

std::string toString_wrap(RF24NetworkHeader& ref)
{
    return std::string(ref.toString());
}

// **************** RF24Network exposed  *****************

BOOST_PYTHON_MODULE(RF24Network)
{
    { //::RF24Network
        typedef bp::class_<RF24Network> RF24Network_exposer_t;
        RF24Network_exposer_t RF24Network_exposer = RF24Network_exposer_t("RF24Network", bp::init<RF24&>((bp::arg("_radio"))));
        bp::scope RF24Network_scope(RF24Network_exposer);
        bp::implicitly_convertible<RF24&, RF24Network>();
        { //::RF24Network::available
            typedef bool (::RF24Network::*available_function_type)();
            RF24Network_exposer.def("available", available_function_type(&::RF24Network::available));
        }
        { //::RF24Network::begin (marked as deprecated)
            typedef void (::RF24Network::*begin_function_type)(::uint8_t, ::uint16_t);
            RF24Network_exposer.def("begin", begin_function_type(&::RF24Network::begin), (bp::arg("_channel"), bp::arg("_node_address")));
        }
        { //::RF24Network::begin
            typedef void (::RF24Network::*begin_function_type)(::uint16_t);
            RF24Network_exposer.def("begin", begin_function_type(&::RF24Network::begin), (bp::arg("_node_address")));
        }
        { //::RF24Network::parent
            typedef ::uint16_t (::RF24Network::*parent_function_type)() const;
            RF24Network_exposer.def("parent", parent_function_type(&::RF24Network::parent));
        }
        { //::RF24Network::peek
            typedef uint16_t (::RF24Network::*peek_header)(::RF24NetworkHeader&);
            RF24Network_exposer.def("peek", peek_header(&::RF24Network::peek), (bp::arg("header")));
        }
        { //::RF24Network::peek
            typedef bp::tuple (*peek_frame)(::RF24Network&, size_t);
            RF24Network_exposer.def("peek", peek_frame(&peek_read_wrap), (bp::arg("maxlen") = MAX_PAYLOAD_SIZE));
        }
        { //::RF24Network::read
            typedef bp::tuple (*read_function_type)(::RF24Network&, size_t);
            RF24Network_exposer.def(
                "read",
                // read_function_type( &::RF24Network::read ),
                read_function_type(&read_wrap), (bp::arg("maxlen") = MAX_PAYLOAD_SIZE));
        }
        { //::RF24Network::update
            typedef void (::RF24Network::*update_function_type)();
            RF24Network_exposer.def("update", update_function_type(&::RF24Network::update));
        }
        { //::RF24Network::write
            typedef bool (*write_function_type)(::RF24Network&, ::RF24NetworkHeader&, bp::object);
            RF24Network_exposer.def("write", write_function_type(&write_wrap), (bp::arg("header"), bp::arg("buf")));
        }

#if defined RF24NetworkMulticast
        { //::RF24Network::multicastLevel
            typedef void (::RF24Network::*multicastLevel_function_type)(::uint16_t);
            RF24Network_exposer.def("multicastLevel", multicastLevel_function_type(&::RF24Network::multicastLevel), (bp::arg("level")));
        }
        { //::RF24Network::multicast
            typedef bool (*multicast_function_type)(::RF24Network&, ::RF24NetworkHeader&, bp::object, ::uint16_t);
            RF24Network_exposer.def("multicast", multicast_function_type(&multicast_wrap), (bp::arg("header"), bp::arg("buf"), bp::arg("level") = 7));
        }
        RF24Network_exposer.def_readwrite("multicastRelay", &RF24Network::multicastRelay);
#endif // defined RF24NetworkMulticast

        { //::RF24Network::is_valid_address
            typedef bool (::RF24Network::*isAddressValid_function_type)(::uint16_t);
            RF24Network_exposer.def("is_valid_address", isAddressValid_function_type(&::RF24Network::is_valid_address), (bp::arg("address")));
        }
        RF24Network_exposer.def_readwrite("txTimeout", &RF24Network::txTimeout);
        RF24Network_exposer.def_readwrite("routeTimeout", &RF24Network::routeTimeout);
        RF24Network_exposer.def_readwrite("networkFlags", &RF24Network::networkFlags);
        RF24Network_exposer.add_property("parent", &RF24Network::parent);
    }

    // **************** RF24NetworkHeader exposed  *****************

    bp::class_<RF24NetworkHeader>("RF24NetworkHeader", bp::init<>())
        .def(bp::init<uint16_t, bp::optional<unsigned char>>((bp::arg("_to"), bp::arg("_type") = (unsigned char)(0))))
        .def("toString", &toString_wrap)
        .def_readwrite("from_node", &RF24NetworkHeader::from_node)
        .def_readwrite("id", &RF24NetworkHeader::id)
        .def_readwrite("next_id", RF24NetworkHeader::next_id)
        .def_readwrite("reserved", &RF24NetworkHeader::reserved)
        .def_readwrite("to_node", &RF24NetworkHeader::to_node)
        .def_readwrite("type", &RF24NetworkHeader::type);
}

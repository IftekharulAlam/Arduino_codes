// CPP program to find the first, second
#define MAX 100000
using namespace std;

int Print3Smallest(int array[], int n)
{
  int MAX = 100000
            int firstmin = MAX, secmin = MAX, thirdmin = MAX;
  for (int i = 0; i < n; i++)
  {
    /* Check if current element is less than
      firstmin, then update first, second and
      third */
    if (array[i] < firstmin)
    {
      thirdmin = secmin;
      secmin = firstmin;
      firstmin = array[i];
    }

    /* Check if current element is less than
      secmin then update second and third */
    else if (array[i] < secmin)
    {
      thirdmin = secmin;
      secmin = array[i];
    }

    /* Check if current element is less than
      then update third */
    else if (array[i] < thirdmin)
      thirdmin = array[i];
  }

  Serial.print(firstmin);
  Serial.print(" ");

  Serial.print(secmin);
  Serial.print(" ");
  Serial.print(thirdmin);
  Serial.println(" ");

}

// Driver code
int main()
{
  int array[] = {4, 9, 1, 32, 12};
  int n = sizeof(array) / sizeof(array[0]);
  Print3Smallest(array, n);
  return 0;
}

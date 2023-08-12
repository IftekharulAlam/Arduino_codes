void back()
{  
  int error;
  while (1)
  {
    error=readSensor();
    wheel(-150,150);
    if(s[2]==1) break;
  }
  p=p-1;
}

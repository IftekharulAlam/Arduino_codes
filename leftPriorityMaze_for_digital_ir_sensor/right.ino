void right()
{  
  int error;
  while(1)
  {
    error=readSensor();
    wheel(150,-150);
    if(s[1]==0 && s[2]==0 && s[3]==0) break;
  }
  while (1)
  {
    error=readSensor();
    wheel(150,-150);
    if(s[2]==1) break;
  }
  path[p]=path[p]+3;
  if(path[p]==4)
  {
    path[p]=0;
    p=p-1;
  }
  else
  {
    p=p+1;
  }
}

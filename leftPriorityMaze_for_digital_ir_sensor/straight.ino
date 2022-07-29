void straight()
{
  int error;
  while(1)
  {
    error=readSensor();
    wheel(150,150);
    if(s[0]==0 && s[4]==0) break;
  }
  path[p]=path[p]+2;
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

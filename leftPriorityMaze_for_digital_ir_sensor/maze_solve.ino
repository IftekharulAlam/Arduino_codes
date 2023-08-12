void maze_solve()
{
  // Boost the speed
  base_L=220;
  base_R=220;
  if (path[p]==0) p=p-1;
  int error;
  error=readSensor();
  wheel(1,1);
  delay(500);
  while(1)
  {
    error==readSensor();
    wheel(180,-180);
    if(s[1]==0 && s[2]==0 && s[3]==0) break;    
  }
  while(1)
  {
    error==readSensor();
    wheel(180,-180);
    if(s[2]==1) break;    
  }
  while(1)
  {
    if(s[2]==1&&((s[0]==1&&s[1]==1) || (s[3]==1&&s[4]==1)))
    {
        if(p<0)
      {
        while(1)
        {
          wheel(1,1);
        }
      }
      else if(path[p]==1)
      {
        wheel(180,180);
        delay(130);
        while(1)
        {
          error=readSensor();
          wheel(180,-180);
          if(s[1]==0 && s[2]==0 && s[3]==0) break;
        }
        while(1)
        {
          error=readSensor();
          wheel(180,-180);
          if(s[2]==1) break;
        }
      }
      else if(path[p]==2)
      {
        while(1)
        {
          error=readSensor();
          wheel(180,180);
          if(s[0]==0 && s[4]==0) break;
        }
      }
      else if(path[p]==3)
      {
        wheel(180,180);
        delay(130);
        while(1)
        {
          error=readSensor();
          wheel(-180,180);
          if(s[1]==0 && s[2]==0 && s[3]==0) break;
        }
        while(1)
        {
          error=readSensor();
          wheel(-180,180);
          if(s[2]==1) break;
        }
      }
      p=p-1;
    }
     else
    {
      line_follow();
    }
  }
}

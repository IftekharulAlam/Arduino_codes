void maze()
{
  int error;
  error=readSensor();
  if(s[0]==1&&s[1]==1&&s[2]==1&&s[3]==1&&s[4]==1) // T-section or maze end
  {
    wheel(150,150);
    delay(130);
    error=readSensor();
    if(s[0]==1&&s[1]==1&&s[2]==1&&s[3]==1&&s[4]==1) // Maze end
      maze_solve();
    else // T-section
      left();
  }
  else if(s[0]==1&&s[1]==1&&s[2]==1) // Left turn available or maze end
  {
    wheel(150,150);
    delay(130);
    error=readSensor();
     if(s[0]==1&&s[1]==1&&s[2]==1&&s[3]==1&&s[4]==1) // Maze end
      maze_solve();
    else // Left turn
      left();
  } 
  else if(s[2]==1&&s[3]==1&&s[4]==1) // T-section or maze end or right turn available
  {
    wheel(150,150);
    delay(25);
    error=readSensor();
    if(s[0]==1&&s[1]==1) // T-section or maze end
    {
      wheel(150,150);
      delay(130);
      error=readSensor();
      if(s[0]==1&&s[1]==1&&s[2]==1&&s[3]==1&&s[4]==1) // Maze end
        maze_solve();
      else // T section
        left();
    }
    else // Right turn available
    {
      wheel(150,150);
      delay(130);
      error=readSensor();
      if(!(s[0]==0&&s[1]==0&&s[2]==0&&s[3]==0&&s[4]==0)) // Straight priority
      {
        straight();
      }
      else // Right turn
      {
        right();
      }
    }
  }
  else if(s[0]==0&&s[1]==0&&s[2]==0&&s[3]==0&&s[4]==0) // Dead end
  {
    back();
  }
  else // No node
  {
    line_follow();
  }
}

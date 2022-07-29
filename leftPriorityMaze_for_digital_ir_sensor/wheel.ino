void wheel(int lm, int rm)
{
  if(lm==0)
  { 
  analogWrite(inC,0);
  analogWrite(inD,0); 
  }
  if(lm>0)
  {
 analogWrite(inC,abs(lm));
  analogWrite(inD,0); 
  }
  else if(lm<0)
  {
  analogWrite(inC,0);
  analogWrite(inD,abs(lm)); 
  }
  if(rm==0)
  {
 
  analogWrite(inA,0);
  analogWrite(inB,0); 
  }
  if(rm>0)
  {
   
  analogWrite(inA,abs(rm));
  analogWrite(inB,0);
  }
  else if(rm<0)
  {
  
  analogWrite(inA,0);
  analogWrite(inB,abs(rm));
  }
  if(lm>254) lm=254;
  if(lm<-254) lm=-254;
  if(rm>254) rm=254;
  if(rm<-254) rm=-254;
}

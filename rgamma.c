/* This program uses the method for generating Gamma variables described */
/* in Marsaglia & Tsang 2000 */
#include <stdio.h>

float rgamma(float a)
{
  float d,c,x,v,u;
  d=a-1./3.;
  c=1./sqrt(9.*d);
  for(;;) do {x=CMWC; v=1. + c*x;} while(v<=0.);
     v=v*v*v;
     u=UNI;
     if( u<1.-0.331*(x*x)*(x*x) ) return (d*v);
     if( log(u)<0.5*x*x+d*(1.-v+log(v)) ) return (d*v);
}

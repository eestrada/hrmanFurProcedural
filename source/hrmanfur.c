#include <stdlib.h>
#include <malloc.h>
#include <ri.h>

#ifdef __cplusplus
extern "C" RtPointer ConvertParameters(RtString paramstr);
extern "C" RtVoid Subdivide(RtPointer data, RtFloat detail);
extern "C" RtVoid Free(RtPointer data);
#endif

RtPointer
ConvertParameters(RtString paramstr)
{
  RtFloat *curve_width;

  /* convert the string to a float */
  curve_width = (RtFloat *)malloc(sizeof(RtFloat));
  *curve_width = atof(paramstr);
  
  /* return the blind data pointer */
  return (RtPointer)curve_width;
}

RtVoid
Subdivide(RtPointer data, RtFloat detail)
{
  RtFloat *curve_width = (RtFloat *)data;
  RtInt nverts[1] = {2};
  RtFloat plist[6]={0.0,0.0,0.0,0.0,1.0,0.0};
  RtFloat wlist[2]={*curve_width, 0.0};
  
  RiDeclare("width","[varying] [float] []");
  
  /* output a curve with the given width */
  RiCurves ( (RtToken)"linear", 1, nverts, (RtToken)"periodic", (RtToken)"P", plist, (RtToken)"width", wlist);
}

RtVoid
Free(RtPointer data)
{
  free(data);
}
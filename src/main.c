#include "ifc.h"
#include <time.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  time_t tnow = time(NULL);
  struct tm *now = localtime(&tnow);

  IFCDate ifcnow = ifc_from_date(*now);
  printf("Today is:\n");
  printf("%s %d, %04d (%s)\n",
      ifc_month_name(ifcnow),
      ifc_day(ifcnow),
      ifcnow.year,
      ifc_weekday_name(ifcnow));
  return 0;
}

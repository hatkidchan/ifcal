#ifndef _IFC_H_
#define _IFC_H_
#include <time.h>

typedef struct ifcdate {
    int year, day;
} IFCDate;

const char *ifc_month_name(IFCDate date);
const char *ifc_month_name_short(IFCDate date);
const char *ifc_weekday_name(IFCDate date);
const char *ifc_weekday_name_short(IFCDate date);

int ifc_day(IFCDate date);
int ifc_week(IFCDate date);
int ifc_weekday(IFCDate date);
int ifc_month(IFCDate date);
int ifc_is_leap(IFCDate date);

IFCDate ifc_from_date(struct tm date);
struct tm ifc_to_date(IFCDate ifc);

#endif

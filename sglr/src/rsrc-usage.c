/*
 $Id: rsrc-usage.c 5413 2001-07-11 10:53:56Z markvdb $
 */
#ifndef WIN32
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#endif

int AT_calcAllocatedSize();

#ifndef WIN32
void printrusage(struct rusage *rusage)
{
  fprintf(stderr, "maxrss %ld\n", rusage->ru_maxrss);
  fprintf(stderr, "ixrss %ld\n", rusage->ru_ixrss);
  fprintf(stderr, "idrss %ld\n", rusage->ru_idrss);
  fprintf(stderr, "isrss %ld\n", rusage->ru_isrss);
  fprintf(stderr, "minflt %ld\n", rusage->ru_minflt);
  fprintf(stderr, "majflt %ld\n", rusage->ru_majflt);
  fprintf(stderr, "nswap %ld\n", rusage->ru_nswap);
  fprintf(stderr, "inblock %ld\n", rusage->ru_inblock);
  fprintf(stderr, "oublock %ld\n", rusage->ru_oublock);
  fprintf(stderr, "msgsnd %ld\n", rusage->ru_msgsnd);
  fprintf(stderr, "msgrcv %ld\n", rusage->ru_msgrcv);
  fprintf(stderr, "nsignals %ld\n", rusage->ru_nsignals);
  fprintf(stderr, "nvcsw %ld\n", rusage->ru_nvcsw);
  fprintf(stderr, "nivcsw %ld\n", rusage->ru_nivcsw);
}
#endif
#ifndef WIN32
struct rusage rsrc_usage;
#endif

double SG_Timer(void)
{
#ifndef WIN32

  static double cur = 0;
  double prev;

  prev = cur;
  if (getrusage(RUSAGE_SELF, &rsrc_usage) == -1) {
    perror("getrusage");
    return (double)0;
  }

  cur  =  (double) (rsrc_usage.ru_utime.tv_sec) +
    (double) ((rsrc_usage.ru_utime.tv_usec) * 1.0e-06);

  prev = cur - prev;
  return prev > 0 ? prev: 0;
#else
	return 0;
#endif
}
#ifndef WIN32
struct rusage flt_rsrc_usage;
#endif

void SG_PageFlt(long *maj, long *min)
{
	#ifndef WIN32
  static long ma, mi, ma_prev, mi_prev;


  ma_prev = ma;
  mi_prev = mi;
  getrusage(RUSAGE_SELF, &flt_rsrc_usage);

  /* printrusage(&flt_rsrc_usage); */

  mi = flt_rsrc_usage.ru_minflt - mi_prev;
  ma = flt_rsrc_usage.ru_majflt - ma_prev;

  *maj = ma;
  *min = mi;
#endif
}

long SG_Allocated(void)
{
  static long allocated = 0L;
  long tmp;

  tmp = allocated;
  allocated = AT_calcAllocatedSize();

  return allocated - tmp;
}

long SG_ResidentSetSize(void)
{
	#ifndef WIN32
  getrusage(RUSAGE_SELF, &rsrc_usage);

  return rsrc_usage.ru_maxrss;
#else
	return 0;
#endif
}



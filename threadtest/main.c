//
// 2015.5, by Penguin
// This test is used to test thread mechnism of Linux
// This is a c version used to compare with the program writed by c++
// by comparing, to study the difference between them
//

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include <sys/sysinfo.h>
#include <sched.h>
#include <unistd.h>


///////////////
// PROTOTYPES
///////////////
void parse_options(int argc, char **argv);
void print_usage(void);

void getSystemProcessorNum(unsigned int *num);

///////////////
// LOCALS
///////////////
unsigned int debug = 0;
const char* const short_options = "hD";
const struct option long_options[] = {
  {"help", 0, NULL, 'h'},
  {"debug", 0, NULL, 'D'}
};

int main(int argc, char* argv[])
{
  unsigned int processorNum;

  printf("This is Penguin's thread test\n");
  
  parse_options(argc, argv);
  
  getSystemProcessorNum(&processorNum);
}

// Three ways to get processor number
void getSystemProcessorNum(unsigned int *num)
{
  unsigned int procNum = 0;

  *num = get_nprocs();
  if (debug)
    printf("processor number returned by get_nprocs function is %d\n", *num);

  procNum = sysconf(_SC_NPROCESSORS_CONF);
  if (debug)
    printf("processor number returned by _SC_NPPROCESSPRS_CONF is %d\n", procNum);

  // if get_nprocs return value is less/equal to one, then it may not be valid
  if (*num <= 1)
  {
    int set;
    cpu_set_t cpu_set;

    if (sched_getaffinity(0, sizeof(cpu_set), &cpu_set) != -1)
    {
      *num = 0;
      for (set = 0; set < CPU_SETSIZE; set++)
      {
        if (CPU_ISSET(set, &cpu_set) != 0)
          (*num)++;
      }
      if (debug)
        printf("CPU_ISSET checking, valid processor number is %d\n", *num);
    }
  }
}

void parse_options(int argc, char **argv)
{
  int option;
  char *opt_arg = NULL;

  do
  {
    option = getopt_long(argc, argv, short_options, long_options, NULL);
    switch(option)
    {
      case 'h':
        print_usage();
        exit(0);

      case 'D':
        debug = 1;
        break;

      case -1:
        break;

      default:
        printf("Undefined parameter!\n");
        print_usage();
        exit(0);
    }
  } while (option != -1);
}

void print_usage(void)
{
  printf("  -h  --help          Display usage information\n");
  printf("  -D  --debug         print debug info\n");
}

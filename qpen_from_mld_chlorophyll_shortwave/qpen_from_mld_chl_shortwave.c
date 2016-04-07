#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include <getopt.h>
#include <errno.h>
double Qpen(double mld, double chl, double shortwave)
{
 double v1,v2,e1,e2,ln,C;
 ln=log(chl);
 C=ln/2.30259;
 v1=0.321+0.008*C+0.132*pow(C,2)+0.038*pow(C,3)-0.017*pow(C,4)-0.007*pow(C,5);
 v2=0.679197-0.008*C-0.132*pow(C,2)-0.038*pow(C,3)+0.017*pow(C,4)+0.007*pow(C,5);
 e1=1.540-0.166*pow(C,2)-0.252*pow(C,3)-0.055*pow(C,4)+0.042*pow(C,5);
 e2=7.925-6.644*C+3.662*pow(C,2)-1.815*pow(C,3)-0.218*pow(C,4)+0.502*pow(C,5);
 return ( 0.47 * shortwave * ( v1 * exp( -mld/e1 ) + v2 * exp( - mld / e2 ) ) );
}
void pdetails()
{
 fputs("Rev 1.0.0 (Thu Jun 11 16:41:38 UTC 2015)\n",stdout);
 exit(0);
}
void usage (char **argv)
{
      fputs("\nUsage               \n",stdout);
      printf("                %s [OPTIONS]\n\n",argv[0]);
      fputs("Arguments \n\n",stdout);
      fputs ("\
                -m --mld Mixed Layer Depth in Meter\n\
                -c --chl Chlorophyll mg m^-3\n\
                -s --shortwave Pressure in w/m^2\n\
                -v --version Show program version\n\
                -h --help Show help\n\
\n\n", stdout);
fputs("Examples :\n\t ",stdout);
printf("%s",argv[0]);
fputs("   --mld=6.69425 --chl=0.19175 --shortwave=238.4\n\t 46.1120550163",stdout);
fputs("\n\n\t OR\n\n\t ",stdout);
printf("%s",argv[0]);
fputs("   -m 6.69425 -c 0.19175 -s 238.4\n\t 46.1120550163\n",stdout);
fputs("\n         If you find any bugs report to ahegde@nio.org / akshay.k.hegde@gmail.com\n\n",stdout);
 exit(0);
}
void empty_check(char *c, char *s)
{
 if (c && c[0] == '\0')
 {
     printf("\n\t%s should not be empty\n\n",s);
     exit(0);
 }
}
int main(int argc, char **argv)
{
 int c, tf=0,cf=0,pf=0; float mld,chl,shortwave;
while (1)
    {
      static struct option long_options[] =
        {
   {"mld", required_argument, 0, 'm'},
          {"chl", required_argument, 0, 'c'},
   {"shortwave", required_argument, 0, 's'},
   {"version", no_argument, 0, 'v'},
    {"help", no_argument, 0, 'h'},
          {0, 0, 0, 0}
        };
      int option_index = 0;
      c = getopt_long(argc, argv,"m:c:s:vh",long_options, &option_index);
      if (c == -1)
        break;
      switch (c)
        {
        case 0:
          if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;
 case 'h':
   usage(argv);
   break;
        case 'v':
          pdetails();
   break;
 case 'm':
          empty_check(optarg,"mld");
   mld = atof(optarg); tf=1;
   break;
 case 'c':
          empty_check(optarg,"chl");
   chl = atof(optarg); cf=1;
   break;
 case 's':
          empty_check(optarg,"shortwave");
   shortwave = atof(optarg); pf=1;
   break;
 case '?':
          break;
        default:
          abort ();
        }
   }
  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }
  if(cf && tf && pf)
  {
   printf("%5.10lf\n", Qpen(mld,chl,shortwave));
   return 0;
  }else
  {
   usage(argv);
  }
}

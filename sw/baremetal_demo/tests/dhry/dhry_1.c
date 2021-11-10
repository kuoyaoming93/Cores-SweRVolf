#define SWERV
/*
 ****************************************************************************
 *
 *                   "DHRYSTONE" Benchmark Program
 *                   -----------------------------
 *
 *  Version:    C, Version 2.1
 *
 *  File:       dhry_1.c (part 2 of 3)
 *
 *  Date:       May 25, 1988
 *
 *  Author:     Reinhold P. Weicker
 *
 ****************************************************************************
 */

#ifdef SWERV
#include <stdio.h>
#include <stdint.h>
extern uint64_t get_mcycle();
#endif

#include "swervolf_print.h"
#include "dhry.h"

/* Global Variables: */

Rec_Pointer     Ptr_Glob,
                Next_Ptr_Glob;
int             Int_Glob;
Boolean         Bool_Glob;
char            Ch_1_Glob,
                Ch_2_Glob;
int             Arr_1_Glob [50];
int             Arr_2_Glob [50] [50];

Enumeration     Func_1 ();
  /* forward declaration necessary since Enumeration may not simply be int */

#ifndef REG
        Boolean Reg = false;
#define REG
        /* REG becomes defined as empty */
        /* i.e. no register variables   */
#else
        Boolean Reg = true;
#endif

/* variables for time measurement: */

#ifdef TIMES
struct tms      time_info;
#define Too_Small_Time (2*HZ)
                /* Measurements should last at least about 2 seconds */
#endif
#ifdef TIME
extern long     time();
                /* see library function "time"  */
#define Too_Small_Time 2
                /* Measurements should last at least 2 seconds */
#endif
#ifdef MSC_CLOCK
extern clock_t  clock();
#define Too_Small_Time (2*HZ)
#endif

long
                Begin_Time,
                End_Time,
                User_Time;

float           Microseconds,
                Dhrystones_Per_Second;

/* end of variables for time measurement */


extern char* strcpy(char*, const char*);

extern Boolean Func_2 (Str_30, Str_30);
extern void Proc_7 (One_Fifty Int_1_Par_Val, One_Fifty Int_2_Par_Val,
                    One_Fifty *Int_Par_Ref);

extern void Proc_8 (Arr_1_Dim Arr_1_Par_Ref, Arr_2_Dim Arr_2_Par_Ref,
                    int Int_1_Par_Val, int Int_2_Par_Val);

extern void Proc_6 (Enumeration Enum_Val_Par,
                    Enumeration *Enum_Ref_Par);

void Proc_5();
void Proc_4();

void Proc_1(Rec_Pointer Ptr_Val_Par);
void Proc_2(One_Fifty *Int_Par_Ref);
void Proc_3(Rec_Pointer *Ptr_Ref_Par);


int
main ()
/*****/

  /* main program, corresponds to procedures        */
  /* Main and Proc_0 in the Ada version             */
{
        One_Fifty       Int_1_Loc;
  REG   One_Fifty       Int_2_Loc;
        One_Fifty       Int_3_Loc;
  REG   char            Ch_Index;
        Enumeration     Enum_Loc;
        Str_30          Str_1_Loc;
        Str_30          Str_2_Loc;
  REG   int             Run_Index;
  REG   int             Number_Of_Runs;

  /* Initializations */

  /* Init UART for communication */
  init_uart();

  Rec_Type rec0;
  Rec_Type rec1;

  Next_Ptr_Glob = &rec0;
  Ptr_Glob = &rec1;

  Ptr_Glob->Ptr_Comp                    = Next_Ptr_Glob;
  Ptr_Glob->Discr                       = Ident_1;
  Ptr_Glob->variant.var_1.Enum_Comp     = Ident_3;
  Ptr_Glob->variant.var_1.Int_Comp      = 40;
  strcpy (Ptr_Glob->variant.var_1.Str_Comp,
          "DHRYSTONE PROGRAM, SOME STRING");
  strcpy (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

  Arr_2_Glob [8][7] = 10;
        /* Was missing in published program. Without this statement,    */
        /* Arr_2_Glob [8][7] would have an undefined value.             */
        /* Warning: With 16-Bit processors and Number_Of_Runs > 32000,  */
        /* overflow may occur for this array element.                   */

  swerv_printf ("\n\r");
  swerv_printf ("Dhrystone Benchmark, Version 2.1 (Language: C)\n\r");
  swerv_printf ("\n\r");
  if (Reg)
  {
    swerv_printf ("Program compiled with 'register' attribute\n\r");
    swerv_printf ("\n\r");
  }
  else
  {
    swerv_printf ("Program compiled without 'register' attribute\n\r");
    swerv_printf ("\n\r");
  }

  #ifndef SWERV
  swerv_printf ("Please give the number of runs through the benchmark: ");
  {
    int n = 1000;
    scanf ("%d", &n);
    Number_Of_Runs = n;
  }
  swerv_printf ("\n\r");
  #else
  // We do not have scanf.  Hardwire number of runs.
  Number_Of_Runs = 1000;
  #endif

  swerv_printf ("Execution starts, %d runs through Dhrystone\n\r", Number_Of_Runs);

  /***************/
  /* Start timer */
  /***************/

#ifdef SWERV
    Begin_Time = get_mcycle();
#else

#ifdef TIMES
  times (&time_info);
  Begin_Time = (long) time_info.tms_utime;
#endif
#ifdef TIME
  Begin_Time = time ( (long *) 0);
#endif
#ifdef MSC_CLOCK
  Begin_Time = clock();
#endif

#endif

  __asm("__perf_start:");

  for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index)
  {
    __asm("__loop_start:");

    Proc_5();
    Proc_4();
      /* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
    Int_1_Loc = 2;
    Int_2_Loc = 3;
    strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
    Enum_Loc = Ident_2;
    Bool_Glob = ! Func_2 (Str_1_Loc, Str_2_Loc);
      /* Bool_Glob == 1 */
    while (Int_1_Loc < Int_2_Loc)  /* loop body executed once */
    {
      Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
        /* Int_3_Loc == 7 */
      Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc);
        /* Int_3_Loc == 7 */
      Int_1_Loc += 1;
    } /* while */
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Proc_8 (Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc);
      /* Int_Glob == 5 */
    Proc_1 (Ptr_Glob);
    for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index)
                             /* loop body executed twice */
    {
      if (Enum_Loc == Func_1 (Ch_Index, 'C'))
          /* then, not executed */
        {
        Proc_6 (Ident_1, &Enum_Loc);
        strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
        Int_2_Loc = Run_Index;
        Int_Glob = Run_Index;
        }
    }
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Int_2_Loc = Int_2_Loc * Int_1_Loc;
    Int_1_Loc = Int_2_Loc / Int_3_Loc;
    Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
      /* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
    Proc_2 (&Int_1_Loc);
      /* Int_1_Loc == 5 */

  } /* loop "for Run_Index" */

  __asm("__perf_end:");

  /**************/
  /* Stop timer */
  /**************/

#ifdef SWERV
    End_Time = get_mcycle();
    swerv_printf("End_time=%d\n\r", (int) End_Time);
#else
#ifdef TIMES
  times (&time_info);
  End_Time = (long) time_info.tms_utime;
#endif
#ifdef TIME
  End_Time = time ( (long *) 0);
#endif
#ifdef MSC_CLOCK
  End_Time = clock();
#endif

#endif

  swerv_printf ("Execution ends\n\r");
  swerv_printf ("\n\r");
  swerv_printf ("Final values of the variables used in the benchmark:\n\r");
  swerv_printf ("\n\r");
  swerv_printf ("Int_Glob:            %d\n\r", Int_Glob);
  swerv_printf ("        should be:   %d\n\r", 5);
  swerv_printf ("Bool_Glob:           %d\n\r", Bool_Glob);
  swerv_printf ("        should be:   %d\n\r", 1);
  swerv_printf ("Ch_1_Glob:           %c\n\r", Ch_1_Glob);
  swerv_printf ("        should be:   %c\n\r", 'A');
  swerv_printf ("Ch_2_Glob:           %c\n\r", Ch_2_Glob);
  swerv_printf ("        should be:   %c\n\r", 'B');
  swerv_printf ("Arr_1_Glob[8]:       %d\n\r", Arr_1_Glob[8]);
  swerv_printf ("        should be:   %d\n\r", 7);
  swerv_printf ("Arr_2_Glob[8][7]:    %d\n\r", Arr_2_Glob[8][7]);
  swerv_printf ("        should be:   Number_Of_Runs + 10\n\r");
  swerv_printf ("Ptr_Glob->\n\r");
  swerv_printf ("  Ptr_Comp:          %d\n\r", (int) Ptr_Glob->Ptr_Comp);
  swerv_printf ("        should be:   (implementation-dependent)\n\r");
  swerv_printf ("  Discr:             %d\n\r", Ptr_Glob->Discr);
  swerv_printf ("        should be:   %d\n\r", 0);
  swerv_printf ("  Enum_Comp:         %d\n\r", Ptr_Glob->variant.var_1.Enum_Comp);
  swerv_printf ("        should be:   %d\n\r", 2);
  swerv_printf ("  Int_Comp:          %d\n\r", Ptr_Glob->variant.var_1.Int_Comp);
  swerv_printf ("        should be:   %d\n\r", 17);
  swerv_printf ("  Str_Comp:          %s\n\r", Ptr_Glob->variant.var_1.Str_Comp);
  swerv_printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n\r");
  swerv_printf ("Next_Ptr_Glob->\n\r");
  swerv_printf ("  Ptr_Comp:          %d\n\r", (int) Next_Ptr_Glob->Ptr_Comp);
  swerv_printf ("        should be:   (implementation-dependent), same as above\n\r");
  swerv_printf ("  Discr:             %d\n\r", Next_Ptr_Glob->Discr);
  swerv_printf ("        should be:   %d\n\r", 0);
  swerv_printf ("  Enum_Comp:         %d\n\r", Next_Ptr_Glob->variant.var_1.Enum_Comp);
  swerv_printf ("        should be:   %d\n\r", 1);
  swerv_printf ("  Int_Comp:          %d\n\r", Next_Ptr_Glob->variant.var_1.Int_Comp);
  swerv_printf ("        should be:   %d\n\r", 18);
  swerv_printf ("  Str_Comp:          %s\n\r",
                                Next_Ptr_Glob->variant.var_1.Str_Comp);
  swerv_printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n\r");
  swerv_printf ("Int_1_Loc:           %d\n\r", Int_1_Loc);
  swerv_printf ("        should be:   %d\n\r", 5);
  swerv_printf ("Int_2_Loc:           %d\n\r", Int_2_Loc);
  swerv_printf ("        should be:   %d\n\r", 13);
  swerv_printf ("Int_3_Loc:           %d\n\r", Int_3_Loc);
  swerv_printf ("        should be:   %d\n\r", 7);
  swerv_printf ("Enum_Loc:            %d\n\r", Enum_Loc);
  swerv_printf ("        should be:   %d\n\r", 1);
  swerv_printf ("Str_1_Loc:           %s\n\r", Str_1_Loc);
  swerv_printf ("        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n\r");
  swerv_printf ("Str_2_Loc:           %s\n\r", Str_2_Loc);
  swerv_printf ("        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n\r");
  swerv_printf ("\n\r");

  User_Time = End_Time - Begin_Time;

  if (User_Time < Too_Small_Time)
  {
    swerv_printf ("User time %d\n\r", User_Time);
    swerv_printf ("Measured time too small to obtain meaningful results\n\r");
    swerv_printf ("Please increase number of runs\n\r");
    swerv_printf ("\n\r");
  }
  else
  {
#ifdef SWERV
    swerv_printf ("Run time = %d clocks for %d Dhrystones\n\r", User_Time, Number_Of_Runs );
    swerv_printf ("Dhrystones per Second per MHz: ");
    swerv_printf ("%d.%02d", 1000000*Number_Of_Runs/User_Time,(100000000*Number_Of_Runs/User_Time) % 100);
#else
#ifdef TIME
    Microseconds = (float) User_Time * Mic_secs_Per_Second
                        / (float) Number_Of_Runs;
    Dhrystones_Per_Second = (float) Number_Of_Runs / (float) User_Time;
#else
    Microseconds = (float) User_Time * Mic_secs_Per_Second
                        / ((float) HZ * ((float) Number_Of_Runs));
    Dhrystones_Per_Second = ((float) HZ * (float) Number_Of_Runs)
                        / (float) User_Time;
#endif
    swerv_printf ("Microseconds for one run through Dhrystone: ");
    swerv_printf ("%6.1f \n\r", Microseconds);
    swerv_printf ("Dhrystones per Second:                      ");
    swerv_printf ("%6.1f \n\r", Dhrystones_Per_Second);

#endif

    swerv_printf ("\n\r");
  }

  while(1);
}


void
Proc_1 (Ptr_Val_Par)
/******************/

REG Rec_Pointer Ptr_Val_Par;
    /* executed once */
{
  REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;
                                        /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */

  structassign (*Ptr_Val_Par->Ptr_Comp, *Ptr_Glob);
  Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Next_Record->variant.var_1.Int_Comp
        = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
  Proc_3 (&Next_Record->Ptr_Comp);
    /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp
                        == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
    /* then, executed */
  {
    Next_Record->variant.var_1.Int_Comp = 6;
    Proc_6 (Ptr_Val_Par->variant.var_1.Enum_Comp,
           &Next_Record->variant.var_1.Enum_Comp);
    Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
    Proc_7 (Next_Record->variant.var_1.Int_Comp, 10,
           &Next_Record->variant.var_1.Int_Comp);
  }
  else /* not executed */
    structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
} /* Proc_1 */


void
Proc_2 (Int_Par_Ref)
/******************/
    /* executed once */
    /* *Int_Par_Ref == 1, becomes 4 */

One_Fifty   *Int_Par_Ref;
{
  One_Fifty  Int_Loc;
  Enumeration   Enum_Loc;

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (Ch_1_Glob == 'A')
      /* then, executed */
    {
      Int_Loc -= 1;
      *Int_Par_Ref = Int_Loc - Int_Glob;
      Enum_Loc = Ident_1;
    } /* if */
  while (Enum_Loc != Ident_1); /* true */
} /* Proc_2 */


void
Proc_3 (Ptr_Ref_Par)
/******************/
    /* executed once */
    /* Ptr_Ref_Par becomes Ptr_Glob */

Rec_Pointer *Ptr_Ref_Par;

{
  if (Ptr_Glob != Null)
    /* then, executed */
    *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
  Proc_7 (10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
} /* Proc_3 */


void
Proc_4 () /* without parameters */
/*******/
    /* executed once */
{
  Boolean Bool_Loc;

  Bool_Loc = Ch_1_Glob == 'A';
  Bool_Glob = Bool_Loc | Bool_Glob;
  Ch_2_Glob = 'B';
} /* Proc_4 */


void
Proc_5 () /* without parameters */
/*******/
    /* executed once */
{
  Ch_1_Glob = 'A';
  Bool_Glob = false;
} /* Proc_5 */


        /* Procedure for the assignment of structures,          */
        /* if the C compiler doesn't support this feature       */
#ifdef  NOSTRUCTASSIGN
memcpy (d, s, l)
register char   *d;
register char   *s;
register int    l;
{
        while (l--) *d++ = *s++;
}
#endif



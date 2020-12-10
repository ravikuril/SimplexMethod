#include<iostream.h>

#include<conio.h>

#include<math.h>

#define CMAX 10
#define VMAX 10

double T[CMAX][VMAX];
double A[6];
float pivotmax;
void data() {
  int
  var, cons;
  cout << "please enter the no of variables in FUNCTION:";
  cin >>
    var;
  cout << "please enter the no of CONSTRAINTS:";
  cin >> cons;
  A[0] =
    var;
  A[1] = cons;
  for (int x = 0; x <= cons; x++) {
    T[x][0] = 0;
    T[0][1] = 0;
  }
  int m, n;
  cout << "enter the coefficient of FUNCTION\n";
  for (m = 1; m <=
    var; m++) {
    cin >> T[0][m + 1];
    for (n = 1; n <= cons; n++)
      T[0][var +n + 1] = 0;
  }

  for (int n1 = 1; n1 <= cons; n1++) {
    cout << "\nenter the coefficients of " << n1 << "th constraints:";
    for (int n2 = 1; n2 <=
      var; n2++) {
      cout << "\n#" << n2 << ":";
      cin >> T[n1][n2 + 1];
    }
  }

  // for identity matrix

  for (int x1 = 1; x1 <= cons; x1++) {
    for (int x2 = 1; x2 <= cons; x2++) {
      if (x1 == x2) {
        T[x1][cons + 1 + x2] = 1;
      } else {
        T[x1][x2 + cons + 2] = 0;
      }
    }
  }

  for (int p1 = 1; p1 <= cons; p1++) {
    cout << "please enter the right hand side of constraint" << p1 << ":";

    cin >> T[p1][1];

  }

}

//*************************************************************************

void calz() {
  float z = 0.0;
  for (int temp = 1; temp <= A[1]; temp++) {
    z = z + T[temp][0] * T[temp][1];

  }
  cout << "\nz result is :" << z << "\n";

}
//****************************************************************************

void pivot() {
  int x, y;
  int t3;

  int cons = A[1];

  int t = 2;
  for (y = 1; y <= (2 * cons + 2); y++) {
    float c1 = 0.0;

    for (x = 1; x <= cons; x++) {
      c1 = c1 + T[x][0] * T[x][t];
    } //calculating c column vaules:
    T[cons + 1][t] = T[0][t] - c1;
    t++;
  }

  int t1 = 2;

  int flag = 0;
  for (int t2 = 2; t2 <= 2 * cons + 2; t2++) //assigning first +ve value to var for further comperision
  {

    if (T[cons + 1][t2] >= 0 && flag == 0) {
      flag++;
      pivotmax = T[cons + 1][t2];
      t3 = t2;
    }
  }

  int flag2 = 0;

  for (int y1 = 1; y1 <= 2 * cons + 2; y1++) {

    if (pivotmax < T[cons + 1][t1 + 1]) {
      flag2++;
      A[2] = t1 + 1; //column max column no:
      pivotmax = T[cons + 1][t1 + 1];
    } else {

    }
    t1++;
  }
  if (flag2 == 0) {
    A[2] = t3;

  }

  A[5] = pivotmax;
  cout << "\npivot max:" << pivotmax << "\n";

}
//*******************************************************
void minratio() {
  float check = -1;
  float temp[10];
  int
  var = A[2];
  int cons = A[1];
  int flag = 1;
  for (int x = 1; x <= cons; x++) {

    if (T[x][var] == 0) {
      temp[x - 1] = -10; //assigning value in place of infinte
    }

    if (T[x][var] != 0) {

      temp[x - 1] = T[x][1] / T[x][var];
    }
    if (temp[x - 1] >= 0 && flag == 1) {
      flag++;
      check = temp[x - 1];
    }

  }
  if (check == -1) //no positive value assigned to var check
  {
    cout << "unbounded problem:";
  }

  for (int x1 = 1; x1 < cons; x1++) {

    if (check > temp[x1] && temp[x1] >= 0) //min ratio check
    {
      check = temp[x1];
    } else {

    }
  }

  for (int x2 = 0; x2 <= cons - 1; x2++) {

    if (check == temp[x2] && check > -1) {
      A[3] = x2 + 1;
    }
  }

  A[4] = check;
  cout << "\nmin ratio:" << A[4];
  int y = A[3];
  int y1 = A[2];

  T[y][0] = T[0][y1]; // assigning value to Cb :

}
//*************************************************************
void gaussjorden() {
  int x, prow, pcol;
  prow = A[3];
  pcol = A[2];
  int cons = A[1];
  // cout<<"row:"<<prow<<"column:"<<pcol<<"cons:"<<cons<<"\n";
  float v = T[prow][pcol];
  cout << "this is pivot element:" << v;
  for (x = 1; x <= 2 * cons + cons; x++) {
    if (v > 0) {
      T[prow][x] = T[prow][x] / v;

    }
    //cout<<"\nTrow column"<<T[a][x]<<T[a][b];
  }
  //3 possible conditions of pivotrow

  if (prow > 0 && prow <= cons) {
    if (prow == 1)

    {

      for (int t1 = 1; t1 <= cons - prow; t1++) {
        float newv = T[prow + t1][pcol];
        for (int m = 1; m < 2 * cons + 2; m++) {
          T[prow + t1][m] = T[prow + t1][m] - newv * T[prow][m];

        }
      }

    }
    if (prow == cons) {
      int x0 = 1;
      if (prow - x0 > 0) {

        for (int t1 = cons; t1 > 1; t1--) {
          float newv = T[prow - x0][pcol];
          for (int m = 1; m < 2 * cons + 2; m++) {
            T[t1 - 1][m] = T[t1 - 1][m] - newv * T[prow][m];
          }
          x0++;
        }

      }
    }
    if (prow > 1 && prow < cons) {
      int flag = prow - 1;
      if (flag > 0) {
        int x0 = 1;
        if (prow - x0 > 0) {
          for (int t1 = prow; t1 > 1; t1--) {
            float newv = T[prow - x0][pcol];

            for (int m = 1; m < 2 * cons + 3; m++) {
              T[t1 - 1][m] = T[t1 - 1][m] - newv * T[prow][m];
            }
          }
          x0++;
        }
      }
      int flag0 = prow + 1;
      if (flag0 <= cons)

      {

        for (int t1 = 1; t1 <= cons - prow; t1++) {
          float newv = T[prow + t1][pcol];
          for (int m = 1; m < 2 * cons + 3; m++) {
            T[prow + t1][m] = T[prow + t1][m] - newv * T[prow][m];

          }
        }
      }

    }

  }

  calz();
  pivot();
}

//************************************************************************
/* int optimal()
				  {   int flag=0;
				  int cons=A[1];
					for(int x=0;x<2*cons+2;x++)
					  {
						if  (0>=T[cons+1][x])
									{}
						else
							{flag++;}

							}
					  if (flag==0)
					  { int var=A[0];
						for(int y=1;y<=var;y++)
						{
						cout<<"\n"<<y<<"variable value:"<<T[y-1][1];
						}
						int Zresult=0;
					  cout<<"z value is:";
					  for(int x1=1;x1<=cons;x1++)

					  { Zresult=+T[x1][0]*T[x1][1];

					  }
					  cout<<"Zresult is:"<<Zresult;
					  return 0;
				  }
				  else
				  {
					return 1;
				  }

				  }
					*/

void main() {
  void data();
  // int optimal();
  void pivot();
  void calz();
  void minratio();
  void gaussjorden();

  int flag = 0;
  data();
  loop2:
    flag++;

  calz();
  pivot();
  minratio();
  gaussjorden();
  if (A[5] == 0) {
    calz();
    cout << "\nvalues of variables are:\n";
    for (int
      var = 1;
      var <= A[1];
      var ++) {
      cout << "#" <<
        var << ":" << T[var][1] << "\n";
    }

  } else {
    if (flag < 5) {
      goto loop2;
    }
  }

  cout << "----------------------------------------------------------------\n";

  for (int x3 = 0; x3 <= 5; x3++) {
    for (int x4 = 0; x4 <= 7; x4++) {
      cout << T[x3][x4] << "\t";
    }
    cout << "\n";
  }

}

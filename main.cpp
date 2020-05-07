#include <ccc_win.h>
#include <vector>

using namespace std;

/**
	Gives the summation of all contents of the given vector
	@param vector of Nums to add
	@return the Summation
*/
float Sigma(vector<float> Nums)
{
	float ans = 0;
	for (unsigned int i = 0; i < Nums.size(); i++)
		ans += Nums[i];
	return ans;
}

/**
	Multiplies each element of one vector with the corresponding element of the other vector
	@param Vector A
	@param Vector B
	@return Vector C
*/
vector <float> Vect_Multip(vector <float> A, vector <float> B)
{
	vector <float> C;
	for (unsigned int i = 0; i < A.size(); i++)
		C.push_back(A[i]*B[i]);
	return C;
}

/**
	solves Linear Regression and returns 2 intersection points
	@param Vector of Points
	@param Regression Line to return
*/
void Solve(vector<Point> Pts, Line& Regr_Ln)
{
  vector <float> Xi , Yi;
  for (unsigned int i=0; i<Pts.size(); i++)
  {
    Xi.push_back(Pts[i].get_x());
    Yi.push_back(Pts[i].get_y());
  }

  float m,c;        // the constants in the line y = m*x+b

  float A = Sigma(Vect_Multip(Xi,Xi)),
        B = Sigma(Xi),
        C = Sigma(Vect_Multip(Xi,Yi)),
        D = Xi.size(),
        E = Sigma(Yi);


  m=(D*C - B*E) / (A*D - B*B);
  c=(A*E - B*C) / (A*D - B*B);

  Regr_Ln = Line(Point(-10, (-10)*m+c), Point(10, 10*m+c));
}

void Plot(vector <Point> Pts)
{
  Line X_axis(Point(-10,0),Point(10,0));
  Line Y_axis(Point(0,-10),Point(0,10));
  Line Ans_Ln;

  for (unsigned int i=0; i<Pts.size(); i++)
    cwin<<Pts[i];

  Solve(Pts, Ans_Ln);

  cwin << Ans_Ln << X_axis << Y_axis;
}

int ccc_win_main()
{
  vector<Point> Pts;
  Plot(Pts);
  Pts.push_back(cwin.get_mouse("Click to Enter a Point:"));
  cwin << Pts[0];
  while(1)
  {
    Pts.push_back(cwin.get_mouse("Click to Enter a Point:"));
    cwin.clear();
    Plot(Pts);
  }
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
// A structure to represent a Point in 2D plane
struct Point
{
    int x, y;
};

// A utility function to find the distance between two points
float dist(struct Point p1,struct  Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

 
// A utility function to swap two elements
void swap(struct Point *a, struct Point *b)
{
    struct Point t = *a;
    *a = *b;
    *b = t;
}
 void bubbleSort(struct Point list[],int n,char c) {
   struct Point temp;
   int i,j;
	
   int swapped = 0;
   if(c=='x'){
   // loop through all numbers 
   for(i = 0; i < n-1; i++) { 
      swapped = 0;
		
      // loop through numbers falling ahead 
      for(j = 0; j < n-1-i; j++) {

         // check if next number is lesser than current no
         //   swap the numbers. 
         //  (Bubble up the highest number)
			
         if(list[j].x > list[j+1].x) {
            swap(&list[j],&list[j+1]);
            swapped = 1;
         }
}
      // if no number was swapped that means 
      //   array is sorted now, break the loop. 
      if(!swapped) {
         break;
      }
   }
	
}
else
{
	for(i = 0; i < n-1; i++) { 
      swapped = 0;
		
      // loop through numbers falling ahead 
      for(j = 0; j < n-1-i; j++) {

         // check if next number is lesser than current no
         //   swap the numbers. 
         //  (Bubble up the highest number)
			
         if(list[j].y > list[j+1].y) {
            swap(&list[j],&list[j+1]);
            swapped = 1;
         }
}
      // if no number was swapped that means 
      //   array is sorted now, break the loop. 
      if(!swapped) {
         break;
      }
   }
}
}
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot 
int partition (struct Point arr[], int low, int high,char c)
{
    struct Point pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    int j;
    if(c=='x')
    {
    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j].x <= pivot.x)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
	else
	{
		for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j].y <= pivot.y)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
	}
}
 
 The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index 
void quickSort(struct Point arr[], int low, int high,char c)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place 
        int pi = partition(arr, low, high,c);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1,c);
        quickSort(arr, pi + 1, high,c);
    }
}*/
 
// A Brute Force method to return the smallest distance between two points
// in P[] of size n
struct Point* bruteForce(struct Point P[], int n)
{
	int x1,y1,x2,y2,i,j;
    float min = 1000000.00;
    for (i = 0; i < n; ++i)
        for (j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
            {
            	 min = dist(P[i], P[j]);
            	 x1=P[i].x;
            	 y1=P[i].y;
            	 x2=P[j].x;
            	 y2=P[j].y;
			}
               
    struct Point *a;
    a=(struct Point *)malloc(sizeof(struct Point)*2);
    a[0].x=x1;a[0].y=y1;a[1].x=x2;a[1].y=y2;
    return a;
    
}
 
// A utility function to find minimum of two float values
/*float min(float x, float y)
{
    return (x < y)? x : y;
}*/
 
 
// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
struct Point* stripClosest(struct Point strip[], int size, float d)
{
    float min = d;  // Initialize the minimum distance as d
    int i,j,x1,y1,x2,y2;
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (i = 0; i < size; ++i)
        for (j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
            {
            	min = dist(strip[i], strip[j]);
            	x1=strip[i].x;
            	y1=strip[i].y;
            	x2=strip[j].x;
            	y2=strip[j].y;
			}
                
    struct Point *res;
    res=(struct Point *)malloc(sizeof(struct Point)*2);
    res[0].x=x1;
    res[0].y=y1;
    res[1].x=x2;
    res[1].y=y2;
    return res;
}
 
// A recursive function to find the smallest distance. The array Px contains
// all points sorted according to x coordinates and Py contains all points
// sorted according to y coordinates
struct Point* closestUtil(struct Point Px[],struct Point Py[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(Px, n);
 
    // Find the middle point
    int mid = n/2;
    struct Point midPoint = Px[mid];
 
 
    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    struct Point Pyl[mid+1];   // y sorted points on left of vertical line
    struct Point Pyr[n-mid-1];  // y sorted points on right of vertical line
    int li = 0, ri = 0,i;  // indexes of left and right subarrays
    for (i = 0; i < n; i++)
    {
      if (Py[i].x <= midPoint.x)
         Pyl[li++] = Py[i];
      else
         Pyr[ri++] = Py[i];
    }
 
    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    struct Point *dl;
    dl=(struct Point *)malloc(sizeof(struct Point)*2);
	dl= closestUtil(Px, Pyl, mid);
	printf("dl values %d %d %d %d\n",dl[0].x,dl[0].y,dl[1].x,dl[1].y);
    struct Point *dr;
    dr=(struct Point *)malloc(sizeof(struct Point)*2);
	dr = closestUtil(Px + mid, Pyr, n-mid);
    printf("dr values %d %d %d %d\n",dr[0].x,dr[0].y,dr[1].x,dr[1].y);
    // Find the smaller of two distances
    float d1,d2;
     int x1,y1,x2,y2;
	d1 = dist(dl[0], dl[1]);
    d2=dist(dr[0],dr[1]);
    float min;
    if(d1<d2)
    {
    		min=d1;
    		x1=dl[0].x;
    		y1=dl[0].y;
    		x2=dl[1].x;
    		y2=dl[1].y;
	}
    
    else
    {
    	min=d2;	
    	x1=dr[0].x;
    	y1=dr[0].y;
    	x2=dr[1].x;
    	y2=dr[1].y;
	}
    
    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    struct Point strip[n];
    int j = 0;
    for (i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < min)
            strip[j] = Py[i], j++;
 
    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    struct Point *p,*r;
    p=(struct Point *)malloc(sizeof(struct Point)*2);
    r=(struct Point *)malloc(sizeof(struct Point)*2);
    float d3;
   
    p=stripClosest(strip, j, min);
    d3 = dist(p[0], p[1]);
    float m2;
    if(d3<min)
    {
    	m2=d3;
    	r[0].x=p[0].x;
    	r[0].y=p[0].y;
    	r[1].x=p[1].x;
    	r[1].y=p[1].y;
    	printf("%f ",d3);
	}
    	
    else
    {
    	m2=min;
    	r[0].x=x1;
    	r[0].y=y1;
    	r[1].x=x2;
    	r[1].y=y2;
    	printf("%f ",min);
	}
    		printf(" result values %d %d %d %d\n",r[0].x,r[0].y,r[1].x,r[1].y);
   return r;
}
 
// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
struct Point* closest(struct Point P[], int n)
{
    struct Point Px[n];
    struct Point Py[n];
    int i;
    for (i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
 
    bubbleSort(Px,n,'x');
    bubbleSort(Py,n,'y');
    printf("after sorting\n");
    for(i=0;i<n;i++)
    {
    	printf("%d %d\n",Px[i].x,Px[i].y);
    }
    for(i=0;i<n;i++)
    	printf("%d %d\n",Py[i].x,Py[i].y);
    // Use recursive function closestUtil() to find the smallest distance
    struct Point *a;
    a=(struct Point *)malloc(sizeof(struct Point)*2);
    a=closestUtil(Px,Py,n);
    return a;
}
 
// Driver program to test above functions
int main()
{
    struct Point p[6];
	p[0].x=2;p[0].y=3;
	p[1].x=6;p[1].y= 2;
	p[2].x= 40; p[2].y= 50; 
	p[3].x=5; p[3].y=1;
	p[4].x=12;p[4].y= 31; 
	p[5].x=3;p[5].y= 4;
    int n = sizeof(p) / sizeof(p[0]);
    struct Point *a;
    a=(struct Point *)malloc(sizeof(struct Point)*2);
    a=closest(p,n);
    printf("The closest pair of points are x1=%d y1=%d x2=%d,y2=%d\n",a[0].x,a[0].y,a[1].x,a[1].y);
    return 0;
}

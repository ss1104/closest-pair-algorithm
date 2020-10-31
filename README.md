# Closest pair algorithm
# Input description
1. First line contains an integer 't' denotes the number of test cases.
2. First line of next 't' lines contains an integer 'n' denotes the number of points in plane.
3. Next line contains contains 'n' space seperated integers denotes the 'X' coordinates in 2D plane. (Random generated number of 'X' coordinate.Dont take input of    those elements,'rand()' function will automatically generates the random number).
4. Again next line contains 'n' space seperated integers denotes the 'Y' coordinates of corresponding 'X' cooedinates.(Random generated number of 'Y'                coordinate.Dont take input of those elements,'rand()' function will automatically generates the random number).

# Output description
. A decimal number represents the answer of the problem statement

# Information of initial storing of data
1. 'v' is a vector of pair stores the coordinates of ith point => v[i]={x,y}
2. 'v1' is a vector of pair also stores the coordinates of ith point but in different order => v1[i] = {y,x};

# Idea 
1. Key idea to solve this problem is divide and conquer algorithm.
2. First sort the vector 'v' in ascending order (on the basis of 'X' coordinates).
3. Similarly sort the vector 'v1' in ascending order (on the basis of 'Y' coordinates)
4. Divide the vector in half and recursively solve for left half and right half,then take the minimum of both.
5. While solving recursively ,when the size of the vector will be <=3 then solve it by bruteforce (O(n^2)).This is the base case.
6. The bruteforce is just take a point and find the distance between this point to all other points, do the same for rest of the points and take the minimum of         them.This will lead to O(n^2) solution.
7. Base case can't contain one point because to find the distance we need atleast 2 points.So Base case occurs when the size of vector become either 2 or 3.
8. While solving for left and right half one case will arise , what if at the line of division of 2D plane ,2 points exists one at left half and other at right       half so that distance between them is less than minimum distance between 2 points at left half and minimum distance between 2 points at right half.
9. Lets call a variable 'mindist' denotes the minimum distance between 2 points over all points at left half and all points at right half respectively (Exclusion        division case).
10. Lets say 'x' is 'X' coordinate of the points of division, lets consider all the points lies at the region having the 'X' coordinates in the range of 
  [x-mindist,x+mindist] (inclusive). This is because if we take any point lies outside this region the horizontal distance will be more than 'mindist' but 
  minimum distance of 2 points over all points at left half and right half is 'mindist'.
11. We will create the vector of pair say 'border' and store the corresponding point in this vector in the sorted order with respect to 'Y' coordinates of all         such points lies in that plane.
12. Now we'll calculate the smallest distance of 2 points among points in the 'border' vector. It can be proved that for each points in 'border' vector maximum        number of comparisons is 7.

Proof for above : Lets create the rectangle of size 'mindist x 2mindist' ,the maximum vertical distance from given point is 'mindist' and the region have the                           horizontal distance of 2*mindist, that's why we are selecting rectangle of dimension 'mindist x 2mindist'. Now lets divide the rectange in                         eight equal parts. This means each equal part will be a square of dimension 'mindist/2 x mindist/2',let's say more than 2 points lie on                           square,so the maximum distance between 2 points will be mindist/sqrt(2) (when both points lies at the ends of the diagonal). But minimum                          distance of 2 points over all points in left and right half is 'mindist' else minimum distance would have been <= mindist/sqrt(2). This                            implies in one square atmost one point will lie ,thus for each point we have to compare with at most 7 points if each square contain 1 point.
                    
                    
13. Lets call variable 'd' as shortest distance between 2 points in given points in that region ,then at the end of the each recursion we have to  
    return min(d,mindist),final answer will be overall minimum of min(d,mindist) over all recursion.
  
# Time Complexity 
1. 'Border' vector is storing the elements from the pre-sorted vector 'v1' , so we dont have to sort the 'border' vector in recursive calls.
2. In each recursion we are storing some elements in 'Border' vector and solve for the 'Border' vector costs O(n) Time complexity.
3. Each recursion cost O(logn) time complexity (divide and conquer), and sorting of initial vectors costs O(nlogn) time.
=> Overall Time complexity = O(nlogn).

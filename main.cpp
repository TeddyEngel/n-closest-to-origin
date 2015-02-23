//
//  main.cpp
//  NPointsToOrigin
//
//  Created by Teddy Engel on 22/02/2015.
//  Copyright (c) 2015 Teddy Engel. All rights reserved.
//

#include <vector>
#include <cmath>
#include <iostream>

// Our point class
class Point2D
{
public:
    Point2D(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
    int x;
    int y;
};

// We don't need the exact distance, the pow-ed distance is fine for comparison
int DistanceToOrigin(const Point2D &point)
{
    return pow(point.x, 2) + pow(point.y, 2);
}

// We sort by the distance to origin, using a simple insertion sort
void SortByDistanceToOrigin(const std::vector<Point2D*> &input, std::vector<Point2D*> &output)
{
    for(auto &point : input)
    {
        int curDistance = DistanceToOrigin(*point);
        bool bInserted = false;
        int j = 0;
        
        for (auto &pointOutput: output)
        {
            int outputDistance = DistanceToOrigin(*pointOutput);
            
            if (curDistance < outputDistance && j > 0)
            {
                output.insert(output.begin()+(j), point);
                bInserted = true;
                break;
            }
            j++;
        }
        if (!bInserted)
        {
            output.push_back(point);
        }
    }
}

// Prints N elements from the vector collection
void PrintNElements(const std::vector<Point2D*> &elements, const int &n)
{
    for (int i = 0; i < elements.size() && i < n; i++)
    {
        std::cout << "(" << elements[i]->x << "," << elements[i]->y << ")" << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    /* n closest points to origin */
    
    // Allocate points
    std::vector<Point2D*> points;
    points.push_back(new Point2D(1, 2));
    points.push_back(new Point2D(9, 4));
    points.push_back(new Point2D(1, 6));
    points.push_back(new Point2D(5, 8));
    points.push_back(new Point2D(3, 0));
    points.push_back(new Point2D(2, 2));
    points.push_back(new Point2D(1, 4));
    points.push_back(new Point2D(7, 6));
    points.push_back(new Point2D(2, 8));
    points.push_back(new Point2D(3, 1));
    points.push_back(new Point2D(6, 4));
    
    // Display initial points
    std::cout << "Our points:" << std::endl;
    for(auto &point : points)
    {
        std::cout << "(" << point->x << "," << point->y << ")" << std::endl;
    }
    
    // We sort the points by distance and insert in the closestPoints collection
    std::vector<Point2D*> closestPoints;
    SortByDistanceToOrigin(points, closestPoints);
    
    // We display the first N elements of the collection
    int n = 5;
    std::cout << "Closest " << n << " points to origin:" << std::endl;
    PrintNElements(closestPoints, n);
    
    // Delete points
    for(auto &point : points)
    {
        delete point;
    }
    closestPoints.clear();
    points.clear();
    
    return 0;
}

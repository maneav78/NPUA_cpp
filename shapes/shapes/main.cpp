#include <iostream>
#include "Shape3d.h"
#include "Cone.h"
#include "Sphere.h"

using namespace std;

template <typename T>
void bubbleSort(T* arr, int n, bool ord) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            bool ordering = ord ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1];
            if (ordering) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    int n;
    cout << "Give the number of Spheres: ";
    cin >> n;
    Sphere* arr = new Sphere[n];
    
    for (int i = 0; i < n; ++i) {
        double radius;
        cout << "Enter the radius for sphere " << i + 1 << ": ";
        cin >> radius;
        arr[i] = Sphere(radius);
    }

    bubbleSort(arr, n, true);
    cout << "Sorted Spheres:" << endl;
    for (int i = 0; i < n; i++) {
        arr[i].print();
    }

    int s;
    cout << "\nGive the number of Cones: ";
    cin >> s;
    Cone* cones = new Cone[s];

    for (int i = 0; i < s; ++i) {
        double radius, height;
        cout << "Enter the radius and height for cone " << i + 1 << ": ";
        cin >> radius >> height;
        cones[i] = Cone(radius, height);
    }
   
    const int m = 100;//without const its not working
    Shape3d* shapes[m];


    for (int i = 0; i < n; ++i) {
        shapes[i] = &arr[i];
    }
    for (int i = 0; i < s; ++i) {
        shapes[n + i] = &cones[i];
    }

    cout << "\nVolumes of all shapes:\n";
    for (int i = 0; i < n + s; ++i) {
        cout << "Volume of " << i+1 << ':' << shapes[i]->volume() << endl;
    }

    int ind = 0;
    for (int i = 1; i < n + s; ++i) {
        if ((shapes[i]->volume() > shapes[ind]->volume()) ||
            (shapes[i]->volume() == shapes[ind]->volume() && shapes[i]->area() < shapes[ind]->area())) {
            ind = i;
        }
    }
    cout << "The shape with the big volume and small area: " << endl;
    cout << "Volume: " << shapes[ind]->volume() << ", Area : " << shapes[ind]->area() << endl;
    shapes[ind]->print();

    delete[] arr;
    delete[] cones;
    delete[] shapes;

    return 0;
}


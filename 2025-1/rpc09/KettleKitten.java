/*
from math import pi
# Kettle Kitten
# 3 19 quantity of kettles | volume of kitten
# 2 3 height and rad of each kettle
# 4 2
# 6 1

n,vol = map(int, input().split())
vol = vol/pi

min = float('inf')
bidx = -1

for i in range(n):
    h,r = map(int, input().split())
    evol =  r * r * h
    if evol < min and evol >= vol:
        min = evol
        bidx = i+1
print(bidx if bidx != -1 else "impossible")
 */

import java.lang.Math;



public class KettleKitten {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int n = sc.nextInt(), bidx = -1;
        double min = Double.MAX_VALUE, vol = sc.nextDouble() / Math.PI;
        for(int i = 0; i< n;i++){
            int h = sc.nextInt();
            int r = sc.nextInt();
            double evol = r * r * h;
            if (evol < min && evol >= vol) {
                min = evol;
                bidx = i + 1;
            }
        }
        System.out.println(bidx != -1 ? bidx : "impossible");
        sc.close();
    }
}
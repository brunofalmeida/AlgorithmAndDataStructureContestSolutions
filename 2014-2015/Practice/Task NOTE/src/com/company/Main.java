package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        ArrayList<Integer> numbers = new ArrayList<Integer>();

        for (int i = 0; i < 8; i++)
            numbers.add(in.nextInt());

        boolean isAscending = true;
        boolean isDescending = true;

        for (int i = 0; i < 8; i++) {
            if (numbers.get(i) != i + 1)
                isAscending = false;

            if (numbers.get(i) != 8 - i)
                isDescending = false;
        }

        if (isAscending)
            System.out.println("ascending\n");
        else if (isDescending)
            System.out.println("descending\n");
        else
            System.out.println("mixed\n");
    }
}

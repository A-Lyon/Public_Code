// TestCode.java - test code for expression tree assignment.
// Author: Chris Wilcox
// Date:   3/19/2017
// Class:  CS165
// Email:  wilcox@cs.colostate.edu

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.MalformedInputException;
import java.util.*;

public class TestCode {

    // Test code for
    public static void main(String[] args) {
        // Instantiate student code
        ExpressionTree eTree = new ExpressionTree();
        Scanner input = new Scanner(System.in);
        String expression = input.nextLine();
        System.out.println("Original Expression: " + expression);

        // Verify parse
        Queue<String> infix = eTree.parse(expression);
        System.out.println("Infix Tokens: " + infix.toString());

        // Verify convert
        List<String> postfix = eTree.convert(infix);
        System.out.println("Postfix Tokens: " + postfix.toString());
        System.out.println("Correct Tokens: [5, 6, 9, *, +, 13, 5, 6, *, /, -]");

        // Verify build
        System.out.println("postfix pre-build: " + postfix.toString());
        eTree.build(postfix);
        System.out.println("Build: complete");
        System.out.println("postfix post build: " + postfix.toString());


	}
}

/*
Original Expression: 5 + 6 * 9 - 13 / (5 * 6)
Infix Tokens: [5, +, 6, *, 9, -, 13, /, (, 5, *, 6, )]
Postfix Tokens: [5, 6, 9, *, +, 13, 5, 6, *, /, -]
*/

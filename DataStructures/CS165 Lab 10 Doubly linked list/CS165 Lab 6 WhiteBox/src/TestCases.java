import org.junit.Test;

import static org.junit.Assert.*;

public class TestCases {

	//Switch which line is commented out in order to test the correct vs broken code
//	TestingFunctions functions = new BlackBoxCorrect();
//	TestingFunctions functions = new BlackBoxIncorrect();
	TestingFunctions functions = new MyFunctions();

	/**
	 * This is a simple validity check for the method greatestCommonDivisor. Checks that the method
	 * returns the correct result for a known GCD problem gcd(2,4) = 2
	 */
	@Test       //*************tells compiler that this is a test*******
	public void testGCD() {

		assertEquals("Error: should return 2", 2, functions.greatestCommonDivisor(2, 4));

	}

	//fails if a  or b negative. fails if a = b;

	@Test
	public void testGCDNegative(){

		assertEquals("Error: should return -1", -1, functions.greatestCommonDivisor(-5, -10));

	}

	@Test
	public void testGCDZero(){

		assertEquals("Error: should return 8", 8, functions.greatestCommonDivisor(0, 8));

	}

	@Test
	public void testGCDSame(){

		assertEquals("Error: should return 8", 8, functions.greatestCommonDivisor(8, 8));

	}

	/**
	 * This is a simple check of the reverseWindow method. Checks if the method will reverse the entire contents
	 * of the passed array correctly.
	 *
	 * ******Use Javadoc to see what these are supposed to do, i.e. reverseWindow()
	 * create arrays that would work correctly
	 *
	 * **** pass same indexes
	 *
	 */
	@Test
	public void testReverseWindow() {
		//create arrays with the expectation vs the input
		int[]start={1, 2, 3, 4, 5};
		int[] end ={3, 2, 1, 4, 5};
		//passing it (0,3)

		functions.reverseWindow(start, 0, 3);

		assertArrayEquals(end, start);
		// (whats expected, whats being passed)
	}

	@Test
	public void testReverseWindowMismatchIndex() {
		//create arrays with the expectation vs the input
		int[]start={1, 2, 3, 4, 5};
		int[] end ={3, 2, 1, 4, 5};
		//passing it (3,0)

		functions.reverseWindow(start, 3, 0);

		assertArrayEquals(end, start);
		// (whats expected, whats being passed)
	}


	@Test
	public void testReverseWindowIndexEqual() {
		//create arrays with the expectation vs the input
		int[]start={1, 2, 3, 4, 5};
		int[] end ={1, 2, 3, 4, 5};
		//passing it (0,0)

		functions.reverseWindow(start, 0, 0);

		assertArrayEquals(end, start);
		// (whats expected, whats being passed)
	}

	//For completion, write additional tests as described in the lab documentation.

	//this is what a test would look like if we were expecting an exception
	//
	@Test(expected = IndexOutOfBoundsException.class)
	public void testReverseWindowOutOfBounds() {
		int[] begin ={1, 2, 3, 4, 5};
		int[] expected ={5, 4, 3, 2, 1};

		functions.reverseWindow(begin, -3, 5);

		assertArrayEquals(begin, expected);
	}

/*
	@Test       //we are making this in class as an example
	public void testGNDNeg() {
		assertEquals(  -1, functions.greatestCommonDivisor(-7,5));

	}
*/


}
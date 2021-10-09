import java.math.BigInteger;
import java.util.Random;

class Karatsuba {
    private final static BigInteger ZERO = new BigInteger("0");
	
	public static BigInteger myMultiply(BigInteger x, BigInteger y) {
        // cutoff to brute force
        int N = Math.max(x.bitLength(), y.bitLength());
        if (N < 10) return x.multiply(y);   
		
        // number of bits divided by 2, rounded up
        N = (N / 2) + (N % 2);

        // x = b + 2^N a,   y = d + 2^N c
        BigInteger b = x.shiftRight(N);
        BigInteger a = x.subtract(b.shiftLeft(N));
        BigInteger d = y.shiftRight(N);
        BigInteger c = y.subtract(d.shiftLeft(N));

        // compute sub-expressions
        BigInteger ac    = myMultiply(a, c);
        BigInteger bd    = myMultiply(b, d);
		BigInteger ad    = myMultiply(a, d);
        BigInteger bc    = myMultiply(b, c);

        return ac.add(bc.add(ad).shiftLeft(N).add(bd.shiftLeft(2 * N)));
    }

    public static BigInteger karatsuba(BigInteger x, BigInteger y) {
        // cutoff to brute force
        int N = Math.max(x.bitLength(), y.bitLength());
        if (N < 10) return x.multiply(y);   
		
        // number of bits divided by 2, rounded up
        N = (N / 2) + (N % 2);

        // x = b + 2^N a,   y = d + 2^N c
        BigInteger b = x.shiftRight(N);
        BigInteger a = x.subtract(b.shiftLeft(N));
        BigInteger d = y.shiftRight(N);
        BigInteger c = y.subtract(d.shiftLeft(N));

        // compute sub-expressions
        BigInteger ac    = karatsuba(a, c);
        BigInteger bd    = karatsuba(b, d);
        BigInteger abcd  = karatsuba(a.add(b), c.add(d));

        return ac.add(abcd.subtract(ac).subtract(bd).shiftLeft(N)).add(bd.shiftLeft(2 * N));
    }

 
    public static void main(String[] args) {
        long start, stop, elapsed;
        Random random = new Random();
        int N = Integer.parseInt(args[0]);
        BigInteger a = new BigInteger(N, random);
        BigInteger b = new BigInteger(N, random);

        start = System.currentTimeMillis(); 
        BigInteger c = karatsuba(a, b);
        stop = System.currentTimeMillis();
		System.out.println(a + " * " + b + " = " + c);
        System.out.println("Time: " + (stop - start));

        start = System.currentTimeMillis(); 
        BigInteger d = a.multiply(b);
        stop = System.currentTimeMillis();
		System.out.println(a + " * " + b + " = " + d);
        System.out.println("Time: " + (stop - start));
		
		start = System.currentTimeMillis(); 
        BigInteger e = myMultiply(a, b);
        stop = System.currentTimeMillis();
		System.out.println(a + " * " + b + " = " + e);
        System.out.println("Time: " + (stop - start));
        
        System.out.println((c.equals(d)));
		System.out.println((c.equals(e)));
    }
}

import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import java.util.Scanner;

public class PercolationStats {
   private int sidelenth;
   private double mean;
   private double stddev;
   private double con_lo;
   private double con_hi;
   private double[] expriments;
   
   public PercolationStats(int n, int trials) {    // perform trials independent experiments on an n-by-n grid
	 if (n < 0 || trials < 0) {
		 throw new IllegalArgumentException("Illegal Argument");
	 }
	 sidelenth = n;
	 if (sidelenth == 1) {
		 mean = 1;
		 stddev = Double.NaN;
		 con_io = Double.NaN;
		 con_hi = Double.NaN;
	 } else {
		 expriments = new double[trials];
		 for (int i = 0; i < trials; i++) {
			 Percolation check_prec = new Precolation(n);
			 int count = 0;
			 while (!check_prec.percolates()) {
				 int row = StdRandom.uniform(n) + 1;
				 int col =  StdRandom.uniform(n) + 1;
				 if check_prec.isOpen(row, col) {
					 check_prec.open(row, col);
					 count++;
				 }
			 }
		 }
		 mean = StdStats.mean(experiments);
         stddev = StdStats.stddev(experiments);
         con_lo = mean - (1.96 * stddev) / Math.sqrt(trials);
         con_hi = mean + (1.96 * stddev) / Math.sqrt(trials);
	 }
   }
   public double mean() {                          // sample mean of percolation threshold
	   return mean;
   }
   public double stddev() {                       // sample standard deviation of percolation threshold
	   return stddev;
   }
   public double confidenceLo() {                  // low  endpoint of 95% confidence interval
	   return con_lo;
   }
   public double confidenceHi() {                  // high endpoint of 95% confidence interval
	   return con_hi;
   }
   public static void main(String[] args) {       // test client (described below)
	   int n = Integer.parseInt(args[0]);
	   int trails = Integer.parseInt(args[1]);
	   PercolationStats prec = new Percolation(n, trails);
	   System.out.println("mean:  " + per.mean());
       System.out.println("stddev:  " + per.stddev());
       System.out.println("confidence Low:  " + per.confidenceLo());
       System.out.println("confidence High:  " + per.confidenceHi());
   }
}
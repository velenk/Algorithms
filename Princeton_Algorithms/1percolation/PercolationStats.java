import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.Stopwatch;

public class PercolationStats {
   private int sidelenth;
   private double mean;
   private double stddev;
   private double[] expriments;
   
   public PercolationStats(int n, int trials) {    // perform trials independent experiments on an n-by-n grid
	 if (n < 0 || trials < 0) {
		 throw new IllegalArgumentException("Illegal Argument");
	 }
	 sidelenth = n;
	 if (sidelenth == 1) {
		 mean = 1;
		 stddev = Double.NaN;
	 } else {
		 expriments = new double[trials];
		 for (int i = 0; i < trials; i++) {
			 Percolation check_prec = new Percolation(n);
			 int count = 0;
			 while (!check_prec.percolates()) {
				 int row = StdRandom.uniform(n) + 1;
				 int col =  StdRandom.uniform(n) + 1;
				 if (!check_prec.isOpen(row, col)) {
					 check_prec.open(row, col);
					 count++;
				 }
			 }
			expriments[i] = (double) count / (n * n);
		 }
		 mean = StdStats.mean(expriments);
         stddev = StdStats.stddev(expriments);
	 }
   }
   public double mean() {                          // sample mean of percolation threshold
	   return mean;
   }
   public double stddev() {                       // sample standard deviation of percolation threshold
	   return stddev;
   }
   public double confidenceLo() {                  // low  endpoint of 95% confidence interval
	   return mean() - 1.96 * stddev() / Math.sqrt(expriments.length);
   }
   public double confidenceHi() {                  // high endpoint of 95% confidence interval
	   return mean() + 1.96 * stddev() / Math.sqrt(expriments.length);
   }
   public static void main(String[] args) {       // test client (described below)
	   StdOut.printf("%-25s\n", "Please input 2 integers");
		int n = StdIn.readInt();
		int trials = StdIn.readInt();
		Stopwatch wt = new Stopwatch();
	   PercolationStats prec = new PercolationStats(n, trials);
	   double elapsed = wt.elapsedTime();
	   StdOut.printf("%-25s= %.15f\n", "elapsed CPU time", elapsed);
	   StdOut.printf("%-25s= %.7f\n", "mean", prec.mean());
		StdOut.printf("%-25s= %.17f\n", "stddev", prec.stddev());
		StdOut.printf("%-25s= [%.15f, %.15f]\n", "%95 confidence interval", prec.confidenceLo(), prec.confidenceHi());
   }
}
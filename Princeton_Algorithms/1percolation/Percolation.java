import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Percolation {
   private WeightedQuickUnionUF uf;
   private boolean []site;
   private int N;
   private int count;
   
   public Percolation(int n) {               // create n-by-n grid, with all sites blocked
	this.N = n;
	this.site = new boolean[N*N+2];
	this.site[0] = this.site[N*N+1] = true;
	uf = new  WeightedQuickUnionUF(N*N+2);
   }
   public    void open(int row, int col) {   // open site (row, col) if it is not open already
	 int pos = (row - 1) * N + col;
	 if (row < 1 || row > N || col < 1 || col > N) {
	 	throw new IndexOutOfBoundsException("index out of bounds");
	 }
	 if (site[pos]) {
		 return;
	 } else {
		 site(pos) = true;
		 count++;
	 }
	 if (row != 1 && site[pos-N]) {
		 uf.union(pos, pos-N);
	 }
	 if (row != N && site[pos+N]) {
		 uf.union(pos, pos+N);
	 }
	 if (col != 1 && site[pos-1]) {
		 uf.union(pos, pos-1);
	 }
	 if (col != N && site[pos+1]) {
		 uf.union(pos, pos+1);
	 }
   }
   public boolean isOpen(int row, int col) {  // is site (row, col) open?
	 if (row < 1 || row > N || col < 1 || col > N) {
		 throw new IndexOutOfBoundsException("index out of bounds");
	 }
	 return site[(row-1)*N+col];
   }
   public boolean isFull(int row, int col) {  // is site (row, col) full?
	 if (row < 1 || row > N || col < 1 || col > N) {
		 throw new IndexOutOfBoundsException("index out of bounds");
	 }
	 return uf.connected((row-1)*N+col, 0);
   }
   public int numberOfOpenSites() {      // number of open sites
	 return count;
   }
   public boolean percolates() {              // does the system percolate?
	 return connected(0, N*N+1);
   }
   public static void main(String[] args) {   // test client (optional)
	 FileInputStream input = new FileInputStream("heart.txt");
	 System.setIn(input);
	 int n;
	 Sanner n = new Sanner(System.in);
	 Percolation perc = new Percolation(n);
	 while (!StdIn.isEmpty()) {
		 row = StdIn.readIn();
		 col = StdIn.readIn();
		 perc.open(row, col);
	 }
	 System.out.println(perc.percolates());
	 System.out.println(perc.numberOfOpenSites());
   }
}
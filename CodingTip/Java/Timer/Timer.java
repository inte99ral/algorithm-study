package 도구;

public class Timer {
	private long[] starts;
	private long[] ends;

	public Timer(int num){
		this.starts = new long[num];
		this.ends = new long[num];
	}

	public void start(int num){
		starts[num] = System.currentTimeMillis();
		return;
	}

	public void end(int num){
		ends[num] = System.currentTimeMillis();
		return;
	}

	public void display(int num){
		double time = (ends[num] - starts[num]) / 1000d;
		System.out.println("[TIME " + num + "] : " + time);
		return;
	}

	public void displayAll(){
		for (int i = 0; i < starts.length; i++)
			System.out.println("[TIME " + i + "] : " + ((ends[i] - starts[i]) / 1000d));
		return;
	}
}

class Tester{
	static final public int tester = 100;
}
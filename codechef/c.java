class clocktest{
	public static void main(String [] args){
		clock c = new clock();

		c.settime("123");

		String to = c.gettime();

		System.out.println(to);
	}
}

class a{
	public static void main(String [] args){
		int orig =42;
		a x= new a();
		int y = x.go(orig);

		System.out.println("out : " + y);
	}

	int go(int i){
		return 2*i;
	}
}



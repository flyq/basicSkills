public class BeerSong{
    public static void main(String args[]){
	int BeerNum = 99;
	String word = "bottles";

	while(BeerNum >= 0)
	    {
		if(BeerNum == 1){
		    word = "bottle";
		}

		System.out.println(BeerNum + " " + word + " " + "of beer on the wall");
		BeerNum -= 1;
				   
	    }
    }
}

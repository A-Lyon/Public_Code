import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class MovieAnalysis {
    ArrayList<Movie> movies;

    /**TODO Finish the constructor
     * Initialize the List of movies
     */
    public MovieAnalysis(){
        movies = new ArrayList<Movie>();
        /* INSERT CODE ABOVE THIS LINE*/
        loadData();
    }

    /**
     * This method has already been completed
     * Initializes the movies list with data from a csv and initializes the ratings list for each movie with
     * 100 random values
     * NOTE: the filepath for IMDB-Movie-Data.csv may need to be adjusted if you are running this in an IDE.
     * Make sure it is just the name of the file for running in zyBooks, however. 
     */
    public void loadData() {
            String movieData = "IMDB-Movie-Data.csv";
            try(Scanner csvReader = new Scanner(new File(movieData))){
               String row = csvReader.nextLine();
                while (csvReader.hasNext()) {
                   row = csvReader.nextLine();
                   String[] data = row.split(",");
                   //'Title' and 'Runtime (Minutes) columns are indices 1 and 7 respectively
                   //create a new movie for each row in csv
                   Movie cur = new Movie(data[0], Integer.parseInt(data[1]));
                   movies.add(cur);
                }
                Random r = new Random(5192020);
               //adds one hundred random ratings to the list for each movie
               for(Movie m : movies) {
                  for (int i = 0; i < 100; i++) {
                    //gives us a number between 0 and 5
                    int rating = r.nextInt(6);
                    m.addRating(rating);
                  }
               } 
                
            } catch (IOException e) {
               System.err.println("Cannot read file: " + movieData);
            }  
            
    }
    /**TODO Complete this method
     * This method should return the Movie object with the name of the function parameter 'title' or null if the movie
     * is not in the list
     * @param title
     */
    public Movie search(String title){
        for (Movie movie : movies) {
            if (movie.getName().equals(title)) {
                return movie;
            }
        }

        return null;
    }

    /**TODO Complete this method
     * This method should return the Movie with the highest average rating(use the getAverageRating() method you
     * created earlier)
     * First you might want to declare and initialize an int variable which will hold the highest rating
     * Second, you might want to create a variable to hold the index of the highest rated movie
     * Third, loop through the movies list and find the highest rated movie
     * Fourth, return the movie from the movies list at the index
     * @return Movie with the highest rating
     */
    public Movie getHighestRated(){
        int high = 0;

        for (int i = 0; i < movies.size(); i++){
            if (movies.get(i).getAverageRating() > movies.get(high).getAverageRating()){
                high = i;
            }
        }
        return movies.get(high);
    }


    /**TODO Complete this method
     * This method should return the movie with the lowest average rating.
     * @return Movie object with the lowest average rating
     */
    public Movie getLowestRated(){
        int low = 0;

        for (int i = 0; i < movies.size(); i++){
            if (movies.get(i).getAverageRating() < movies.get(low).getAverageRating()){
                low = i;
            }
        }
        return movies.get(low);
    }
    
    /**Do NOT change the main method below.
     * It has been completed and is required for testing.
     */
    
    public static void main(String[] args){
        MovieAnalysis m = new MovieAnalysis();
        for(int i = 0; i < 10; i++) {
            System.out.println(m.movies.get(i));
        }
        Movie moana = m.search("Moana");
        if (moana != null) {
            System.out.println("Moana Found!");
        } else {
            System.out.println("Moana wasn't found");
        }
        System.out.printf("Moana rating: %.2f\n", moana.getAverageRating());
        Movie highest = m.getHighestRated();
        System.out.println("Highest Rated movie: " + highest.getName());
        Movie lowest = m.getLowestRated();
        System.out.println("Lowest Rated movie: " + lowest.getName());
    }
}

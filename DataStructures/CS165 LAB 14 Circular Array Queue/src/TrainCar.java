/*
 * This class is used for testing ArrayQueue using an Object other than Integers and Strings
 */
public class TrainCar {
	
	String type;
	String color;
	int id;
	
	public TrainCar(String type, String color, int id) {
		this.type = type;
		this.color = color;
		this.id = id;
	}


	//this is a good testing method for objects. This will give us the ability to cast objects because we have
	//checked if obj1 is related to object 2
	public boolean equals(Object o) {
		if (!(o instanceof TrainCar)) {
			return false;
		}
		TrainCar c = (TrainCar) o;
		
		return this.type.equals(c.type) && this.id == c.id;
	}
	
	public String toString() {
		return color + " " + type + ": " + id;
	}
	 public int hashCode() {
        return super.hashCode();
    }
	
	public static void main(String[] args) {
		
	}

	
}

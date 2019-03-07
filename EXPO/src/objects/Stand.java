package objects;

import java.io.Serializable;

import javax.ejb.EJB;
import javax.ejb.Stateless;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;


@Stateless
@Entity
public class Stand implements Serializable{

	@Id @GeneratedValue
	String Id;
	
	int Score;	
	
	public Stand() {
		Score = 0;
	}
	
	public Stand(int score) {
		super();
		Score = score;
	}
	
	public String getId() {
		return Id;
	}
	
	public void setId(String id) {
		Id = id;
	}
	
	public int getScore() {
		return Score;
	}
	
	public void setScore(int score) {
		Score = score;
	}
	
	
}

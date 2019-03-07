package objects;

import java.io.Serializable;

import javax.ejb.EJB;
import javax.ejb.Stateless;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;


@Entity
public class Stand implements Serializable{

	@Id @GeneratedValue
	String id;
	
	int score;	
	
	public Stand() {
		score = 0;
	}
	
	public Stand(int score) {
		super();
		this.score = score;
	}
	
	public String getId() {
		return id;
	}
	
	public void setId(String id) {
		this.id = id;
	}
	
	public int getScore() {
		return score;
	}
	
	public void setScore(int score) {
		this.score = score;
	}
	
	
}

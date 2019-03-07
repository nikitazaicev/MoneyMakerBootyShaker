package objects;

import java.io.Serializable;
import java.util.HashSet;
import java.util.Set;

import javax.ejb.EJB;
import javax.ejb.Stateless;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;

import javax.persistence.OneToMany;


@Entity
public class Stand implements Serializable{

	@Id @GeneratedValue
	private String id;
	
	private int score;
	
	@OneToMany
	private Set<TimeStats> historikk;
	
	public Stand() {
		score = 0;
	}
	
	public Stand(int score) {
		super();
		this.score = score;
		historikk = new HashSet<TimeStats>();
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

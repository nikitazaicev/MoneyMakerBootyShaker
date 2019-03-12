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
import javax.persistence.Table;


@Entity
@Table(schema = "expo", name = "stand")
public class Stand implements Serializable{

	@Id @GeneratedValue
	private String id;
	
	private int score;
	private int antStemmer;
	
	@OneToMany(mappedBy="stand")
	private Set<TimeStats> historikk;
	
	public Stand() {
		score = 0;
		setAntStemmer(0);
	}
	
	public Stand(int score, int antStemmer) {
		super();
		this.score = score;
		this.setAntStemmer(antStemmer);
		historikk = new HashSet<TimeStats>();
	}
	
	public void vote(int vote) {
		// Hver bruker skal kunne sende inn en vote
		// Denne voten skal lagres
		score = score + vote;
		//setAntStemmer(getAntStemmer() + 1);
	}
	public void reVote(int gammel, int nyVote) {
		// Hente inn gammel vote fra session
		// Fjern gammel vote fra score og legg til nyVote
		// antStemmer forblir dem samme 
		score = score - gammel + nyVote;
	}
	public int averageVote() {
		return score / antStemmer;
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

	public int getAntStemmer() {
		return antStemmer;
	}

	public void setAntStemmer(int antStemmer) {
		this.antStemmer = antStemmer;
	}
	
}

package objects;

import java.io.Serializable;
import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

import javax.ejb.EJB;
import javax.ejb.Stateless;
import javax.persistence.Entity;
import javax.persistence.FetchType;
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

	@OneToMany(mappedBy = "stand", fetch = FetchType.EAGER)
	private ArrayList<TimeStats>  historikk;
	
	public Stand() {
		score = 0;
		antStemmer=0;
	}
	
	public Stand(int score, int antStemmer) {
		super();
		this.score = score;
		this.antStemmer = antStemmer;
		historikk = new ArrayList<TimeStats>();
	}
	public Stand(String id, int score) {
		super();
		this.score = score;
		historikk = new ArrayList<TimeStats>();
	}
	/**
	 * denne her er egentlig ubrukelig siden man kan bruke reVote() med 0 som gammel stemme
	 * @param vote
	 * @return timestamp of when vote was made "now()"
	 */
	public TimeStats vote(int vote) {
		// Hver bruker skal kunne sende inn en vote
		// Denne voten skal lagres
		score = score + vote;
		antStemmer++;
		TimeStats ts = new TimeStats(this,score);
		historikk.add(ts);
		return ts;
		//setAntStemmer(getAntStemmer() + 1);
	}
	/**
	 * 
	 * @param gammel stemmen session har mappet til en stand
	 * @param nyVote ny stemme man submitter
	 * @return timestamp of when vote was made "now()"
	 */
	public TimeStats reVote(int gammel, int nyVote) {
		// Hente inn gammel vote fra session
		// Fjern gammel vote fra score og legg til nyVote
		// antStemmer forblir dem samme 
		score = score - gammel + nyVote;
		TimeStats ts = new TimeStats(this,score);
		historikk.add(ts);
		return ts;
	}

	public ArrayList<TimeStats> getHistorikk() {
		return historikk;
	}

	public void setHistorikk(ArrayList<TimeStats> historikk) {
		this.historikk = historikk;
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

	@Override
	public String toString() {
		return "Stand [id=" + id + ", score=" + score + ", antStemmer=" + antStemmer + ", historikk=" + historikk.toString() + "]";
	}
	
}

package objects;

import java.io.Serializable;
import java.sql.Time;
import java.sql.Timestamp;
import java.time.LocalDateTime;

import javax.ejb.EJB;
import javax.ejb.Stateless;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.IdClass;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.Table;

import org.eclipse.persistence.internal.jpa.config.sequencing.GeneratedValueImpl;

import javax.persistence.JoinColumn;


@IdClass(TimeStatsId.class)
@Entity
@Table(schema = "expo", name = "timestats")
public class TimeStats implements Serializable {


	@Id @ManyToOne //@JoinColumn(name="id")
	private Stand stand;
	@Id 
	private Timestamp tiden;
	private int score;
	

	
	public TimeStats() {
		this.tiden = Timestamp.valueOf(LocalDateTime.now()); 
	}
	
	public TimeStats(Stand stand, Timestamp tiden, int score) {
		this.stand = stand;
		this.tiden = Timestamp.valueOf(LocalDateTime.now()); 
		this.score = score;
	}
	
	
	
	public Stand getStand() {
		return stand;
	}

	public void setStand(Stand stand) {
		this.stand = stand;
	}

	public Timestamp getTime() {
		return tiden;
	}
	public void setTime(Timestamp time) {
		tiden = time;
	}
	public int getScore() {
		return score;
	}
	public void setScore(int score) {
		this.score = score;
	}

	public int compareTo(TimeStats ts) {
		return tiden.compareTo(ts.getTime());
	}

}

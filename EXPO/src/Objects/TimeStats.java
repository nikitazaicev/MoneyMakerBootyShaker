package Objects;

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
import javax.persistence.OneToMany;

import org.eclipse.persistence.internal.jpa.config.sequencing.GeneratedValueImpl;


@Stateless
@Entity
@IdClass(TimeStatsId.class)
public class TimeStats implements Serializable {

	@Id @GeneratedValue @OneToMany(mappedBy="Stand")
	String id;
	@Id 
	Timestamp tiden;
	int score;
	
	public TimeStats() {
		this.tiden = Timestamp.valueOf(LocalDateTime.now()); 
	}
	
	public TimeStats(String id, Timestamp tiden, int score ) {
		this.id = id;
		this.tiden = Timestamp.valueOf(LocalDateTime.now()); 
		this.score = score;
	}
	
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
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

}

package objects;

import java.io.Serializable;
import java.sql.Timestamp;
import java.time.LocalDateTime;

public class TimeStatsId implements Serializable {

	private String stand;
	private Timestamp tiden;
	
	public TimeStatsId() {
		this.tiden = Timestamp.valueOf(LocalDateTime.now()); 
	}
	
	public TimeStatsId(String stand, Timestamp tiden) {
		this.stand = stand;
		this.tiden = tiden;
	}
	
	public String getStand() {
		return stand;
	}

	public void setStand(String stand) {
		this.stand = stand;
	}

	public Timestamp getTiden() {
		return tiden;
	}

	public void setTiden(Timestamp tiden) {
		this.tiden = tiden;
	}


}

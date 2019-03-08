package objects;

import java.io.Serializable;
import java.sql.Timestamp;
import java.time.LocalDateTime;

public class TimeStatsId implements Serializable {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String id;
	private Timestamp tiden;
	
	public TimeStatsId() {
		this.tiden = Timestamp.valueOf(LocalDateTime.now()); 
	}
	
	public TimeStatsId(String id, Timestamp tiden) {
		this.id = id;
		this.tiden = tiden;
	}
	
	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public Timestamp getTiden() {
		return tiden;
	}

	public void setTiden(Timestamp tiden) {
		this.tiden = tiden;
	}


}

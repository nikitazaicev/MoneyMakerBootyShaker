package objects;

import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

@Stateless
public class TimeStatsEAO {
	
	@PersistenceContext(name = "expo")
	private EntityManager em;
	
	public TimeStats getStats(String id) {
		return em.find(TimeStats.class, id);
	}

}

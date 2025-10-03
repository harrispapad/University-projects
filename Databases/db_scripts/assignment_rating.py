import mysql.connector
import random

# Function to create a connection to the database
def create_connection():
    return mysql.connector.connect(
        host="localhost",
        user="harris",
        password="Database@10",
        database="masterchef"
    )

# Function to load all assignments for a given episode
def load_assignments(cursor, episode_id):
    cursor.execute("SELECT assignment_id FROM episode_assignment WHERE episode_id = %s", (episode_id,))
    return [row[0] for row in cursor.fetchall()]
    
def load_judges(cursor, episode_id):
    cursor.execute("SELECT judge_id FROM episode_judge WHERE episode_id = %s", (episode_id,))
    return [row[0] for row in cursor.fetchall()]

def create_assignment_rating(cursor, conn, episode_id):
    # Load episode assignments
    episode_assignments = load_assignments(cursor, episode_id)
    
    # Load episode judges
    episode_judges = load_judges(cursor, episode_id)
    
    for assignment_id in episode_assignments:
        cursor.execute("SELECT chef_id FROM assignment WHERE assignment_id = %s", (assignment_id,))
        chef_id = cursor.fetchone()[0]
        
        for judge_id in episode_judges:
            rating = random.randint(1, 5)
            # Insert the rating into the assignment_rating table
            cursor.execute("INSERT INTO assignment_rating (assignment_id, judge_id, chef_id, rating) VALUES (%s, %s, %s, %s)", (assignment_id, judge_id, chef_id, rating))
    conn.commit()

def main():
    conn = create_connection()
    cursor = conn.cursor()
    
    for year in range(3, 4):
        for episode in range(year * 100 + 1, year * 100 + 11):
            create_assignment_rating(cursor, conn, episode)
    
    cursor.close()
    conn.close()

main()

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

def create_episode_judge(cursor, episode_id, year):
    # Load episode assignments
    episode_assignments = load_assignments(cursor, episode_id)
    
    # Find the chefs of the current episode
    episode_chefs = []
    for assignment_id in episode_assignments:
        cursor.execute("SELECT chef_id from assignment where assignment_id = %s", (assignment_id,))
        chef_id = cursor.fetchone()[0]  # Fetch the chef_id
        episode_chefs.append(chef_id)  # Add chef_id to the list
    
    # Fetch year's chefs
    cursor.execute("SELECT chef_id FROM chef WHERE year = %s", (year,))
    year_chefs = [row[0] for row in cursor.fetchall()]
    
    # Filter out chefs that are already cooking in this episode
    available_chefs = [chef_id for chef_id in year_chefs if chef_id not in episode_chefs]
    
    # Choose three random chefs from the available chefs list
    random_judges = random.sample(available_chefs, min(3, len(available_chefs)))
    
    # Insert judges into the episode_judge table
    for judge in random_judges:
        cursor.execute("INSERT INTO episode_judge (episode_id, judge_id) VALUES (%s, %s)", (episode_id, (judge * 10)))
    
def main():
    conn = create_connection()
    cursor = conn.cursor()
    
    for year in range(3, 4):
        for episode in range(year * 100 + 1, year * 100 + 11):
           create_episode_judge(cursor, episode, year)
    
    conn.commit()
    cursor.close()
    conn.close()

main()

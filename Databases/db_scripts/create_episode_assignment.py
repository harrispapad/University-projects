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

def load_ethnicities(cursor):
    cursor.execute("SELECT name FROM ethnicity")
    return [row[0] for row in cursor.fetchall()]

# Function to load all assignments for a given year
def load_assignments(cursor, year):
    cursor.execute("SELECT assignment_id FROM assignment WHERE year = %s", (year,))
    return [row[0] for row in cursor.fetchall()]

# Function to create an episode with 10 assignments, each with a unique ethnicity
def create_episode_assignment(cursor, conn, episode_id, year, all_assignments, ethnicities):
    if len(all_assignments) < 10:
        print("Not enough assignments available for the year")
        return

    if len(ethnicities) < 10:
        print("Not enough unique ethnicities available")
        return

    # Randomly select 10 assignments from the loaded assignments
    selected_assignments = random.sample(all_assignments, 10)

    # Randomly select 10 unique ethnicities
    selected_ethnicities = random.sample(ethnicities, 10)

    # Insert the episode assignments into the database
    for assignment_id in selected_assignments:
        sql = "INSERT INTO episode_assignment (episode_id, assignment_id) VALUES (%s, %s)"
        cursor.execute(sql, (episode_id, assignment_id))
        all_assignments.remove(assignment_id)  # Remove the assignment from the list to prevent duplication


    conn.commit()

# Main function
def main():
    conn = create_connection()
    cursor = conn.cursor()

    # Load all ethnicities
    ethnicities = load_ethnicities(cursor)

    # Define the years for the episodes and assignments
    for year in range(3, 4):
        # Load all assignments for the given year
        all_assignments = load_assignments(cursor, year)

        # Create 10 episodes for the current year
        for episode_id in range(1, 11):
            # Adjust episode_id based on the year
            adjusted_episode_id = year * 100 + episode_id

            # Create episode assignments
            create_episode_assignment(cursor, conn, adjusted_episode_id, year, all_assignments, ethnicities)

    cursor.close()
    conn.close()

main()

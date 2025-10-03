import mysql.connector
import random

conn = mysql.connector.connect(
    host="localhost",
    user="harris",
    password="Database@10",
    database="masterchef"
)
cursor = conn.cursor()

def generate_assignments(cursor, conn, num_years):
    for year in range(3, num_years + 1):
        for assignment_id in range(year * 100, (year + 1) * 100):
            # Select an ethnicity for the assignment
            cursor.execute("SELECT name FROM ethnicity ORDER BY RAND() LIMIT 1")
            ethnicity_row = cursor.fetchone()
            if ethnicity_row:
                ethnicity = ethnicity_row[0]  # Extract the value from the tuple
            else:
                print(f"No ethnicity found at assignment {assignment_id} for year {year}")
                continue  # Skip this iteration if no ethnicity is found

            # Select chef
            cursor.execute("SELECT chef_id FROM chef WHERE ethnicity = %s and year = %s ORDER BY RAND() LIMIT 1", (ethnicity, year))
            chef_row = cursor.fetchone()
            if chef_row:
                chef_id = chef_row[0]  # Extract the value from the tuple
            else:
                print(f"No chef found for ethnicity {ethnicity} at assignment {assignment_id} for year {year}")
                continue  # Skip this iteration if no chef is found

            # Select one recipe per ethnicity
            cursor.execute("SELECT recipe_id FROM recipe WHERE ethnicity = %s ORDER BY RAND() LIMIT 1", (ethnicity,))
            recipe_row = cursor.fetchone()
            if recipe_row:
                recipe_id = recipe_row[0]  # Extract the value from the tuple
            else:
                print(f"No recipe found for ethnicity {ethnicity} at assignment {assignment_id} for year {year}")
                continue  # Skip this iteration if no recipe is found

            # Insert the assignment into the "assignment" table
            sql = "INSERT INTO assignment (assignment_id, chef_id, recipe_id, year) VALUES (%s, %s, %s, %s)"
            cursor.execute(sql, (assignment_id, chef_id, recipe_id, year))
            conn.commit()

generate_assignments(cursor, conn, 3)  # Call the function for 3 years

cursor.close()
conn.close()


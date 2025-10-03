# Databases

This directory contains the course project for Databases, implementing a complete database system for a **MasterChef cooking competition** management platform.

**Partners:** Stroubakou Eirini, Fragkonikolaki Kyriaki

## Contents

### Project Overview

A comprehensive database design and implementation for managing a MasterChef-style cooking competition, tracking:

- **Chefs**: Personal information, ethnicity, expertise levels, years of participation
- **Recipes**: Dishes with difficulty levels, cooking times, portions, ethnic cuisines, meal types, and tags
- **Ingredients**: Recipe components with quantities and food groups
- **Equipment**: Kitchen tools and appliances required for recipes
- **Episodes**: Competition episodes with years and episode numbers
- **Judges**: Competition judges participating in episodes
- **Assignments**: Chef-recipe pairings with ratings and results
- **Ratings**: Judge evaluations of chef performances

### Key Features

- Chef performance tracking and average ratings by chef and cuisine
- Episode management with chef and judge assignments
- Recipe categorization by cuisine, meal type, difficulty, and dietary tags
- Ingredient and equipment tracking for each recipe
- Automated rating calculations and chef expertise level updates
- Complex queries for competition analysis and statistics

### Database Files

- **`er diagram.png`**: Entity-Relationship diagram
- **`relational-schema.mwb`**: MySQL Workbench relational schema model
- **`DDL.sql`**: Data Definition Language script (table creation, constraints, indexes)
- **`DML.sql`**: Data Manipulation Language script (sample data insertion)
- **`DDL + DML.sql`**: Combined DDL and DML script
- **`queries.txt`**: Sample analytical queries including:
  - Average ratings per chef and cuisine
  - Chef participation by ethnicity and year
  - Recipe analysis by difficulty and cooking time
  - Ingredient and equipment statistics

### Utilities (`db_scripts/`)

Python scripts for database population and automation:

- `create_assignments.py`: Generate chef-recipe assignments
- `create_episode_assignment.py`: Assign chefs to episodes
- `create_episode_judge.py`: Assign judges to episodes
- `assignment_rating.py`: Populate rating data
- Stored procedures: `calculate_assignment_rating`, `UpdateChefExpertiseLevel`

### Documentation

- **`Report_db.pdf`**: Complete project report with design decisions and analysis

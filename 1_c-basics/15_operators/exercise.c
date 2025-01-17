/*
 * Complete the snek_score function in exercise.c.
 * Sneklang is unique™ in that its toolchain gives developers
 * a "project score" that's dependent on how maintainable
 * and "high quality" their codebase is.
 * The larger the score, the harder it is to work in the project.
 *
 * The score is calculated as follows:
 * * Multiply the number of files by the number of commits
 *   to get the size factor.
 * * Add the size factor to the number of contributors
 *   to get the complexity factor.
 * * Multiply the complexity factor by the average bug criticality
 *   (a number between 0 and 1) to get the final score.
 */
float snek_score(
  int num_files,
  int num_contributors,
  int num_commits,
  float avg_bug_criticality
) {
  return (float)((num_files * num_commits)+num_contributors) * avg_bug_criticality;
}

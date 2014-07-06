#ifndef MAP_REDUCE_H
#define MAP_REDUCE_H

/*!
 * QtConcurrent::mappedReduced Example
 * And finally a quick example of mappedReduced.
 * The key difference in mappedReduced is that a second function is provided that is used to reduce the intermediate results.
 * In this example I just used a function that concatenates strings; the end result is an upper-cased, concatenated string.
 */
void RunMapReduceExample();

#endif

// //////////////////////////////////////////////////////////
// sort.h
// Copyright (c) 2013,2020 Stephan Brumme. All rights reserved.
// see http://create.stephan-brumme.com/disclaimer.html
//

// g++ -O3 sort.cpp -o sort -std=c++11

// All sort algorithms follow the same syntax as std::sort
// i.e.: quickSort(container.begin(), container.end());
//
// They sort the container in-place.
// All but merge sort require no significant additional memory
// (just some stack for a few variable and maybe a copy of a single element).
//
// You can provide your own less-than operator, too
// i.e.: quickSort(container.begin(), container.end(), myless());

#pragma once

#include <algorithm>  // std::iter_swap
#include <iterator>   // std::advance, std::iterator_traits
#include <functional> // std::less


/// Bubble Sort, allow user-defined less-than operator
template <typename iterator, typename LessThan>
void bubbleSort(iterator first, iterator last, LessThan lessThan)
{
  if (first == last)
    return;

  // usually "last" points beyond the last element
  // now it points directly to that last element
  --last;
  // only one element => it's sorted
  if (first == last)
    return;

  bool swapped;
  do
  {
    // reset swapped flag
    swapped = false;

    auto current = first;
    while (current != last)
    {
      // bubble up
      auto next = current;
      ++next;

      // two neighbors in wrong order ? swap them !
      if (lessThan(*next, *current))
      {
        std::iter_swap(current, next);
        swapped = true;
      }

      ++current;
    }

    // last element is already sorted now
    --last; // remove this line if you only have a forward iterator

    // last will move closer towards first
  } while (swapped && first != last);
}


/// Bubble Sort with default less-than operator
template <typename iterator>
void bubbleSort(iterator first, iterator last)
{
  bubbleSort(first, last, std::less<typename std::iterator_traits<iterator>::value_type>());
}


// /////////////////////////////////////////////////////////////////////


/// Selection Sort, allow user-defined less-than operator
template <typename iterator, typename LessThan>
void selectionSort(iterator first, iterator last, LessThan lessThan)
{
  for (iterator current = first; current != last; ++current)
  {
    // find smallest element in the unsorted part and remember its iterator in "minimum"
    auto minimum = current;
    auto compare = current;
    ++compare;

    // walk through all still unsorted elements
    while (compare != last)
    {
      // new minimum found ? save its iterator
      if (lessThan(*compare, *minimum))
        minimum = compare;

      // next element
      ++compare;
    }

    // add minimum to the end of the already sorted part
    if (current != minimum)
      std::iter_swap(current, minimum);
  }
}


/// Selection Sort with default less-than operator
template <typename iterator>
void selectionSort(iterator first, iterator last)
{
  selectionSort(first, last, std::less<typename std::iterator_traits<iterator>::value_type>());
}


// /////////////////////////////////////////////////////////////////////


/// Insertion Sort, allow user-defined less-than operator
template <typename iterator, typename LessThan>
void insertionSort(iterator first, iterator last, LessThan lessThan)
{
  if (first == last)
    return;

  // skip first element, consider it as sorted
  auto current = first;
  ++current;

  // insert all remaining unsorted elements into the sorted elements
  while (current != last)
  {
    // insert "compare" into the already sorted elements
    auto compare = std::move(*current);

    // find location inside sorted range, beginning from the right end
    auto pos = current;
    while (pos != first)
    {
      // stop if left neighbor is not smaller
      auto left = pos;
      --left;
      if (!lessThan(compare, *left))
        break;

      // shift that left neighbor one position to the right
      *pos = std::move(*left);
      pos  = std::move( left); // same as --pos
    }

    // found final position
    if (pos != current)
      *pos = std::move(compare);

    // sort next element
    ++current;
  }
}


/// Insertion Sort with default less-than operator
template <typename iterator>
void insertionSort(iterator first, iterator last)
{
  insertionSort(first, last, std::less<typename std::iterator_traits<iterator>::value_type>());
}


// /////////////////////////////////////////////////////////////////////


/// Shell Sort, allow user-defined less-than operator
template <typename iterator, typename LessThan>
void shellSort(iterator first, iterator last, LessThan lessThan)
{
  auto numElements = std::distance(first, last);
  if (numElements <= 1)
    return;

  // sequence taken from Wikipedia (Marcin Ciura)
  static const int OptimalIncrements[] =
  { 68491, 27396, 10958, 4383, 1750, 701, 301, 132, 57, 23, 10, 4, 1, 0 };
  size_t increment = OptimalIncrements[0];
  size_t incrementIndex = 0;
  // increment must not be bigger than the number of elements to be sorted
  while (increment >= numElements)
    increment = OptimalIncrements[++incrementIndex];

  // stumble through all increments in descending order
  while (increment > 0)
  {
    auto stripe = first;
    auto offset = increment;
    std::advance(stripe, offset);
    while (stripe != last)
    {
      // these iterators are always "increment" apart
      auto right = stripe;
      auto left  = stripe;
      std::advance(left, -int(increment));

      // value to be sorted
      auto compare = *right;

      // note: stripe is simply the same as first + offset
      // but operator+() is expensive for non-random access iterators
      auto posRight = offset;
      // only look at values between "first" and "last"
      while (true)
      {
        // found right spot ?
        if (!lessThan(compare, *left))
          break;

        // no, still not correct order: shift bigger element to the right
        *right = std::move(*left);

        // go one step to the left
        right  = left;

        posRight -= increment;
        if (posRight < increment)
          break;
        std::advance(left, -int(increment));
      }

      // found sorted position
      if (posRight != offset)
        *right = std::move(compare);

      // next stripe
      ++stripe;
      ++offset;
    }

    // smaller increment
    increment = OptimalIncrements[incrementIndex++];
  }
}


/// Shell Sort with default less-than operator
template <typename iterator>
void shellSort(iterator first, iterator last)
{
  shellSort(first, last, std::less<typename std::iterator_traits<iterator>::value_type>());
}


// /////////////////////////////////////////////////////////////////////


/// Heap Sort, allow user-defined less-than operator
template <typename iterator, typename LessThan>
void heapSort(iterator first, iterator last, LessThan lessThan)
{
  // just use STL code
  std::make_heap(first, last, lessThan);
  std::sort_heap(first, last, lessThan);
}


/// Heap Sort with default less-than operator
template <typename iterator>
void heapSort(iterator first, iterator last)
{
  // just use STL code
  std::make_heap(first, last);
  std::sort_heap(first, last);
}


// /////////////////////////////////////////////////////////////////////


/// n-ary Heap Sort, allow user-defined less-than operator
template <size_t Width, typename iterator, typename LessThan>
void naryHeapSort(iterator first, iterator last, LessThan lessThan)
{
  // width must be at least two
  if (Width < 2)
  {
    naryHeapSort<2>(first, last, lessThan);
    return;
  }

  auto numElements = std::distance(first, last);
  if (numElements < 2)
    return;

  // based on n-ary heap sort pseudo code from http://de.wikipedia.org/wiki/Heapsort

  struct SiftDown
  {
    void operator() (iterator first, size_t pos, size_t stop, LessThan lessThan)
    {
      std::advance(first, pos);
      auto parent = first;
      auto child  = first;

      auto value = std::move(*parent);

      while (pos * Width + 1 < stop)
      {
        // locate children
        auto increment = pos * (Width - 1) + 1;
        pos += increment;
        std::advance(child, increment);

        // figure out how many children we have to check
        auto numChildren = Width;
        if (numChildren + pos > stop)
          numChildren = stop - pos;

        // find the biggest of them
        if (numChildren > 1)
        {
          iterator scan = child;
          ++scan;

          size_t maxPos = 0;
          for (size_t i = 1; i < numChildren; i++, scan++)
            // element in "scan" bigger than current best ?
            if (lessThan(*child, *scan))
            {
              maxPos = i;
              child = scan;
            }

          pos += maxPos;
        }

        // is no child bigger than the parent ? => done
        if (!lessThan(value, *child))
        {
          *parent = std::move(value);
          return;
        }

        // move biggest child one level up, parent one level down and continue
        *parent = std::move(*child);
        parent  =            child;
      }

      *child = std::move(value);
    }
  } heapify;

  // build heap where the biggest elements are placed in front
  size_t firstLeaf = (numElements + Width - 2) / Width;
  for (size_t i = firstLeaf; i > 0; i--)
    heapify(first, i - 1, numElements, lessThan);

  // take heap's largest element and move it to the end
  // => build sorted sequence beginning with last (= largest) element
  for (auto i = numElements - 1; i > 0; i--)
  {
    --last;
    std::iter_swap(first, last);
    // re-adjust shrinked heap
    heapify(first, 0, i, lessThan);
  }
}


/// n-ary Heap Sort with default less-than operator
template <size_t Width, typename iterator>
void naryHeapSort(iterator first, iterator last)
{
  naryHeapSort<Width, iterator>(first, last, std::less<typename std::iterator_traits<iterator>::value_type>());
}


// /////////////////////////////////////////////////////////////////////


/// Merge Sort, allow user-defined less-than operator
template <typename iterator, typename LessThan>
void mergeSort(iterator first, iterator last, LessThan lessThan, size_t size = 0)
{
  // determine size if not known yet
  if (size == 0 && first != last)
    size = std::distance(first, last);
  // by the way, the size parameter can be omitted but
  // then we are required to compute it each time which can be expensive
  // for non-random access iterators

  // one element is always sorted
  if (size <= 1)
    return;

  // divide into two partitions
  auto firstHalf  = size / 2;
  auto secondHalf = size - firstHalf;
  auto mid = first;
  std::advance(mid, firstHalf);

  // recursively sort them
  mergeSort(first, mid,  lessThan, firstHalf);
  mergeSort(mid,   last, lessThan, secondHalf);

  // merge sorted partitions
  std::inplace_merge(first, mid, last, lessThan);
}


/// Merge Sort with default less-than operator
template <typename iterator>
void mergeSort(iterator first, iterator last)
{
  mergeSort(first, last, std::less<typename std::iterator_traits<iterator>::value_type>());
}


// /////////////////////////////////////////////////////////////////////


/// in-place Merge Sort, allow user-defined less-than operator
template <typename iterator, typename LessThan>
void mergeSortInPlace(iterator first, iterator last, LessThan lessThan, size_t size = 0)
{
  // determine size if not known yet
  if (size == 0 && first != last)
    size = std::distance(first, last);
  // by the way, the size parameter can be omitted but
  // then we are required to compute it each time which can be expensive
  // for non-random access iterators

  // one element is always sorted
  if (size <= 1)
    return;

  // divide into two partitions
  auto firstHalf  = size / 2;
  auto secondHalf = size - firstHalf;
  auto mid = first;
  std::advance(mid, firstHalf);

  // recursively sort them
  mergeSortInPlace(first, mid,  lessThan, firstHalf);
  mergeSortInPlace(mid,   last, lessThan, secondHalf);

  // merge partitions (left starts at "first", right starts and "mid")
  // move iterators towards the end until they meet
  auto right = mid;
  while (first != mid)
  {
    // next value of both partitions in wrong order (smaller one belongs to the left)
    if (lessThan(*right, *first))
    {
      // this value must be moved to the right partition
      auto misplaced = std::move(*first);

      // this value belongs to the left partition
      *first = std::move(*right);

      // misplaced value must be inserted at correct position in the right partition
      auto scan = right;
      auto next = scan;
      ++next;
      // move smaller one position to the left
      while (next != last && lessThan(*next, misplaced))
        *scan++ = std::move(*next++);

      // found the spot !
      *scan = std::move(misplaced);
    }

    ++first;
  }
}


/// in-place Merge Sort with default less-than operator
template <typename iterator>
void mergeSortInPlace(iterator first, iterator last)
{
  mergeSortInPlace(first, last, std::less<typename std::iterator_traits<iterator>::value_type>());
}


// /////////////////////////////////////////////////////////////////////


/// Quick Sort, allow user-defined less-than operator
template <typename iterator, typename LessThan>
void quickSort(iterator first, iterator last, LessThan lessThan)
{
  auto numElements = std::distance(first, last);
  // already sorted ?
  if (numElements <= 1)
    return;

  auto pivot = last;
  --pivot;

  // choose middle element as pivot (good choice for partially sorted data)
  if (numElements > 2)
  {
    auto middle = first;
    std::advance(middle, numElements/2);
    std::iter_swap(middle, pivot);
  }

  // scan beginning from left and right end and swap misplaced elements
  auto left  = first;
  auto right = pivot;
  while (left != right)
  {
    // look for mismatches
    while (!lessThan(*pivot, *left)  && left != right)
      ++left;
    while (!lessThan(*right, *pivot) && left != right)
      --right;
    // swap two values which are both on the wrong side of the pivot element
    if (left != right)
      std::iter_swap(left, right);
  }

  // move pivot to its final position
  if (pivot != left && lessThan(*pivot, *left))
    std::iter_swap(pivot, left);

  // subdivide
  quickSort(first,  left, lessThan);
  quickSort(++left, last, lessThan); // *left itself is already sorted
}


/// Quick Sort with default less-than operator
template <typename iterator>
void quickSort(iterator first, iterator last)
{
  quickSort(first, last, std::less<typename std::iterator_traits<iterator>::value_type>());
}


// /////////////////////////////////////////////////////////////////////


/// Intro Sort, allow user-defined less-than operator
template <typename iterator, typename LessThan>
void introSort(iterator first, iterator last, LessThan lessThan)
{
  // switch to Insertion Sort if the (sub)array is small
  auto numElements = std::distance(first, last);
  if (numElements <= 16)
  {
    // already sorted ?
    if (numElements <= 1)
      return;

    // micro-optimization for exactly 2 elements
    if (numElements == 2)
    {
      if (lessThan(*(first + 1), *first))
        std::iter_swap(first + 1, first);
      return;
    }

    // between 3 and 16 elements
    insertionSort(first, last, lessThan);
    return;
  }

  auto pivot = last;
  --pivot;

  // choose middle element as pivot (good choice for partially sorted data)
  auto middle = first;
  std::advance(middle, numElements/2);
  std::iter_swap(middle, pivot);

  // scan beginning from left and right end and swap misplaced elements
  auto left  = first;
  auto right = pivot;
  while (left != right)
  {
    // look for mismatches
    while (!lessThan(*pivot, *left)  && left != right)
      ++left;
    while (!lessThan(*right, *pivot) && left != right)
      --right;
    // swap two values which are both on the wrong side of the pivot element
    if (left != right)
      std::iter_swap(left, right);
  }

  // move pivot to its final position
  if (pivot != left && lessThan(*pivot, *left))
    std::iter_swap(pivot, left);

  // subdivide
  introSort(first,  left, lessThan);
  introSort(++left, last, lessThan); // *left itself is already sorted
}


/// Intro Sort with default less-than operator
template <typename iterator>
void introSort(iterator first, iterator last)
{
  introSort(first, last, std::less<typename std::iterator_traits<iterator>::value_type>());
}

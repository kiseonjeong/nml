#ifndef NDARRAY_H
#define NDARRAY_H

namespace nml
{
	// The N Dimensional Array
	template <typename var, const unsigned int N> class ndarray
	{
		// Variables
	public:
		const dim& dm;			// dimension information

		// Functions
	public:
		void create(const dim& di);			// Create an array
		void release();			// Release an array
		void set(const var& val);			// Set a value
		const int length() const;			// Get a total length
		var* ptr() const;			// Get a data pointer
		bool empty() const;			// Check an array
		void cout() const;			// Console out for an array
		void _cout(const int nspace = 0) const;			// Console out for an array
		void subdim(const dim& di, var* tdata);			// Set sub-dimensional array
		void subdata(var* ddata, const int tidx);			// Set sub-dimensional data

		// Operators
	public:
		ndarray& operator=(const ndarray& obj);			// data copy operator
		const ndarray<var, N - 1>& operator[](const int idx) const;			// sub-dimensional array access operator (read)
		ndarray<var, N - 1>& operator[](const int idx);			// sub-dimensional array access operator (write)
		const var& operator()(const int idx) const;			// data access operator (read)
		var& operator()(const int idx);			// data access operator (write)

		// Constructors & Destructor
	public:
		ndarray();
		ndarray(const dim& di);
		ndarray(const dim& di, const var& val);
		ndarray(const ndarray& obj);
		virtual ~ndarray();

		// Variables
	protected:
		ndarray<var, N - 1> sub;			// sub-dimension array
		dim _dm;			// dimension information
		int didx;			// dimensional index
		int dlen;			// dimensional length
		var* ddata;			// dimensional data
		int step;			// width step
		int tidx;			// total index (now unused variable)
		int tlen;			// total length
		var* tdata;			// total data

		// Functions
	protected:
		virtual void setObject();			// Set an object
		virtual void copyObject(const ndarray& obj);			// Copy the object
		virtual void clearObject();			// Clear the object
		void widthStep();			// Calculate a width step

	};

	// The 1 Dimensional Array
	template <typename var> class ndarray<var, 1>
	{
		// Variables
	public:
		const dim& dm;			// dimension information

		// Functions
	public:
		void create(const dim& di);			// Create an array
		void release();			// Release an array
		void set(const var val);			// Set a value
		const int length() const;			// Get a total length
		var* ptr() const;			// Get a data pointer
		bool empty() const;			// Check the array
		void cout() const;			// Console out for an array
		void _cout(const int nspace = 0) const;			// Console out for an array
		void subdim(const dim& di, var* tdata);			// Set sub-dimensional array
		void subdata(var* ddata, const int tidx);			// Set sub-dimensional data

		// Operators
	public:
		ndarray& operator=(const ndarray& obj);			// data copy operator
		const var& operator[](const int idx) const;			// data access operator (read)
		var& operator[](const int idx);			// data access operator (write)
		const var& operator()(const int idx) const;			// data access operator (read)
		var& operator()(const int idx);			// data access operator (write)

		// Constructors & Destructor
	public:
		ndarray();
		ndarray(const dim& di);
		ndarray(const dim& di, const var& val);
		ndarray(const ndarray& obj);
		virtual ~ndarray();

		// Variables
	protected:
		dim _dm;			// dimension information
		int didx;			// dimensional index
		int dlen;			// dimensional length
		var* ddata;			// dimensional data
		int step;			// width step
		int tidx;			// total index
		int tlen;			// total length
		var* tdata;			// total data

		// Functions
	protected:
		virtual void setObject();			// Set an object
		virtual void copyObject(const ndarray& obj);			// Copy the object
		virtual void clearObject();			// Clear the object
		void widthStep();			// Calculate a width step

	};
}

#include "Ndarray.hpp"

#endif
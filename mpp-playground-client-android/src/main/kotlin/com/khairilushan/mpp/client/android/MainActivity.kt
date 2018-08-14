package com.khairilushan.mpp.client.android

import android.content.Context
import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.support.v7.widget.DividerItemDecoration
import android.support.v7.widget.LinearLayoutManager
import android.text.Editable
import android.text.TextWatcher
import android.view.View
import android.view.inputmethod.InputMethodManager
import android.widget.Toast
import com.khairilushan.mpp.viewmodel.ProjectItemViewModel
import com.khairilushan.mpp.viewmodel.SearchProjectViewModel
import com.khairilushan.mpp.viewmodel.SearchProjectViewModelImpl
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity(), SearchProjectViewModel.Outputs {
    private val adapter = ProjectAdapter()
    private val viewModel: SearchProjectViewModel.Inputs by lazy {
        SearchProjectViewModelImpl(this)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        setupRecyclerView()
        setupSearchEditText()
        setupSearchButton()
        viewModel.onViewCreated()
    }

    override fun onDestroy() {
        super.onDestroy()
        viewModel.onViewDestroyed()
    }

    private fun setupSearchEditText() {
        editTextSearch.addTextChangedListener(object : TextWatcher {
            override fun afterTextChanged(p0: Editable?) {
                viewModel.onSearchTextFieldChanged(p0.toString())
            }

            override fun beforeTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {}
            override fun onTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {}
        })
    }

    private fun setupSearchButton() {
        buttonSearch.setOnClickListener { viewModel.onSearchButtonClicked() }
    }

    private fun setupRecyclerView() {
        val decoration = DividerItemDecoration(this, DividerItemDecoration.VERTICAL)
        recyclerView.layoutManager = LinearLayoutManager(this)
        recyclerView.addItemDecoration(decoration)
        recyclerView.adapter = adapter
    }

    override fun startLoading() {
        progressBar.visibility = View.VISIBLE
    }

    override fun finishLoading() {
        progressBar.visibility = View.GONE
    }

    override fun shouldUpdateData(data: List<ProjectItemViewModel>) {
        adapter.setItems(data)
    }

    override fun shouldDismissKeyboard() {
        val imm = getSystemService(Context.INPUT_METHOD_SERVICE) as InputMethodManager
        imm.hideSoftInputFromWindow(editTextSearch.windowToken, 0)

    }

    override fun showErrorMessage(message: String) {
        Toast.makeText(this, message, Toast.LENGTH_LONG).show()
    }
}

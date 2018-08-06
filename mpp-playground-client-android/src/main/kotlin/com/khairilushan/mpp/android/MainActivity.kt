package com.khairilushan.mpp.android

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.support.v7.widget.DividerItemDecoration
import android.support.v7.widget.LinearLayoutManager
import android.widget.Toast
import com.khairilushan.mpp.datasource.ProjectDataSource
import com.khairilushan.mpp.datasource.network.SearchProjectService
import com.khairilushan.mpp.interactor.Failure
import com.khairilushan.mpp.interactor.SearchProjectInteractor
import com.khairilushan.mpp.interactor.Success
import com.khairilushan.mpp.repository.ProjectRepositoryImpl
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.coroutines.experimental.CommonPool
import kotlinx.coroutines.experimental.android.UI

val DEFAULT_KEYWORD = "kotlin"

class MainActivity : AppCompatActivity() {
    private val adapter = ProjectAdapter()
    private val interactor: SearchProjectInteractor by lazy {
        val service = SearchProjectService()
        val network = ProjectDataSource.Network(service)
        val repository = ProjectRepositoryImpl(network)
        SearchProjectInteractor(repository, CommonPool, UI)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        setupRecyclerView()
        setupSearchButton()
        searchProject()
    }

    private fun setupSearchButton() {
        buttonSearch.setOnClickListener {
            if (editTextSearch?.text.toString().isEmpty()) return@setOnClickListener
            searchProject()
        }
    }

    private fun setupRecyclerView() {
        val decoration = DividerItemDecoration(this, DividerItemDecoration.VERTICAL)
        recyclerView.layoutManager = LinearLayoutManager(this)
        recyclerView.addItemDecoration(decoration)
        recyclerView.adapter = adapter
    }

    private fun searchProject() {
        val currentText = editTextSearch.text?.toString().orEmpty()
        val keyword = if (currentText.isEmpty()) DEFAULT_KEYWORD else currentText
        val params = SearchProjectInteractor.Params(keyword)
        interactor.execute(params) { result ->
            when (result) {
                is Success ->
                    adapter.setItems(result.result.map { it.mapToViewModel() })
                is Failure ->
                    Toast.makeText(this, result.message, Toast.LENGTH_LONG).show()
            }
        }
    }
}

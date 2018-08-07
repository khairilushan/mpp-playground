//
//  ViewController.swift
//  mpp-playground-client-ios
//
//  Created by Khairil Ushan on 8/4/18.
//  Copyright © 2018 Khairil Ushan. All rights reserved.
//

import UIKit
import Mpp

final class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {

    private lazy var searchEditText: UITextField = {
        let text = UITextField()
        text.translatesAutoresizingMaskIntoConstraints = false
        text.placeholder = "Cari di Github.com"
        text.layer.cornerRadius = 8
        text.layer.borderWidth = 1
        text.layer.borderColor = UIColor.lightGray.cgColor
        self.view.addSubview(text)
        return text
    }()

    private lazy var tableView: UITableView = {
        let tv = UITableView()
        tv.translatesAutoresizingMaskIntoConstraints = false
        tv.dataSource = self
        tv.delegate = self
        tv.register(
            ProjectTableViewCell.nib,
            forCellReuseIdentifier: ProjectTableViewCell.identifier
        )
        self.view.addSubview(tv)
        return tv
    }()

    private lazy var searchButton: UIButton = {
        let button = UIButton(type: .custom)
        button.translatesAutoresizingMaskIntoConstraints = false
        button.titleLabel?.font = .boldSystemFont(ofSize: 13)
        button.setTitle("SEARCH", for: .normal)
        button.setTitleColor(.black, for: .normal)
        button.addTarget(self, action: #selector(onSearchButtonClicked), for: .touchUpInside)
        self.view.addSubview(button)
        return button
    }()

    private var projects: [MppProject] = []

    override func viewDidLoad() {
        super.viewDidLoad()
        setupView()
        requestProjectList(keyword: "kotlin")
    }

    @objc private func onSearchButtonClicked() {
        guard let keyword = searchEditText.text, !keyword.isEmpty else { return }
        requestProjectList(keyword: keyword)
    }

    private func setupView() {
        title = "MPP Playground"
        let textAttributes = [NSAttributedStringKey.foregroundColor: UIColor.white]
        navigationController?.navigationBar.titleTextAttributes = textAttributes
        navigationController?.navigationBar.isTranslucent = false
        navigationController?.navigationBar.barTintColor = UIColor(
            red: 0.15,
            green: 0.25,
            blue: 0.52,
            alpha: 1
        )
        NSLayoutConstraint.activate([
            searchEditText.topAnchor.constraint(equalTo: topLayoutGuide.topAnchor, constant: 16),
            searchEditText.leadingAnchor.constraint(equalTo: view.leadingAnchor, constant: 16),
            searchEditText.trailingAnchor.constraint(equalTo: view.trailingAnchor, constant: -16),
            searchEditText.heightAnchor.constraint(equalToConstant: 40),

            searchButton.topAnchor.constraint(equalTo: searchEditText.topAnchor),
            searchButton.trailingAnchor.constraint(
                equalTo: searchEditText.trailingAnchor,
                constant: -8
            ),
            searchButton.bottomAnchor.constraint(equalTo: searchEditText.bottomAnchor),

            tableView.topAnchor.constraint(equalTo: searchEditText.bottomAnchor, constant: 10),
            tableView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            tableView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            tableView.bottomAnchor.constraint(equalTo: view.bottomAnchor, constant: 10),
        ])
    }

    private func requestProjectList(keyword: String) {
        let interactor = MppComKhairilushanMppInteractor.createSearchProjectInteractor()
        let params = MppSearchProjectInteractorParams(keyword: keyword)
        interactor.execute(params: params) { [weak self] (result) -> MppStdlibUnit in
            if let success = result as? MppResultSuccess,
               let projects = success.result as? [MppProject] {
                self?.reloadData(projects)
            } else if let failure = result as? MppResultFailure {
                print(failure.message)
            }
            return MppStdlibUnit()
        }
    }

    private func reloadData(_ projects: [MppProject]) {
        self.projects = projects
        tableView.reloadData()
    }

    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    func tableView(
        _ tableView: UITableView,
        estimatedHeightForRowAt indexPath: IndexPath
    ) -> CGFloat {
        return ProjectTableViewCell.height
    }

    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return UITableViewAutomaticDimension
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return projects.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(for: indexPath) as ProjectTableViewCell
        cell.bind(with: projects[indexPath.row])
        return cell
    }
}

extension UITableView {
    func dequeueReusableCell<T: UITableViewCell>(for indexPath: IndexPath) -> T where T: ReusableCell {
        return dequeueReusableCell(withIdentifier: T.identifier, for: indexPath) as! T
    }
}

